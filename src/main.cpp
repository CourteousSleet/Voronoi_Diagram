#ifdef _WIN32
#include <windows.h>
#include <GL/gl.h>

void SetupPixelFormat(HDC hdc) { 
    PIXELFORMATDESCRIPTOR pfd = {
        sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        32,
        0, 0, 0, 0, 0, 0,
        0, 0,
        0, 0, 0, 0, 0,
        24,
        8,
        0,
        PFD_MAIN_PLANE,
        0,
        0, 0, 0
    };

    int pixelFormat = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, pixelFormat, &pfd);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = {};
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "OpenGLWindowClass";
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, wc.lpszClassName, "OpenGL Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);
    ShowWindow(hwnd, nCmdShow);

    HDC hdc = GetDC(hwnd);
    SetupPixelFormat(hdc);
    HGLRC hglrc = wglCreateContext(hdc);
    wglMakeCurrent(hdc, hglrc);

    MSG msg = {};
    while (msg.message != WM_QUIT) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            SwapBuffers(hdc);
        }
    }

    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(hglrc);
    ReleaseDC(hwnd, hdc);
    DestroyWindow(hwnd);

    return 0;
}

#elif __linux__
#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glx.h>

GLXContext CreateGLContext(Display* display, Window window) {
    static int visual_attribs[] = { None };
    int numberOfFramebufferConfigurations = 0;
    GLXFBConfig* fbc = glXChooseFBConfig(display, DefaultScreen(display), visual_attribs, &numberOfFramebufferConfigurations);
    XVisualInfo* vi = glXGetVisualFromFBConfig(display, fbc[0]);
    GLXContext glc = glXCreateContext(display, vi, NULL, GL_TRUE);
    XFree(vi);
    XFree(fbc);
    return glc;
}

int main() {
    Display* display = XOpenDisplay(nullptr);
    if (display == nullptr) {
        return -1;
    }

    int screen = DefaultScreen(display);
    Window root = RootWindow(display, screen);

    XSetWindowAttributes swa;
    swa.event_mask = ExposureMask | KeyPressMask;
    Window window = XCreateWindow(display, root, 0, 0, 800, 600, 0, CopyFromParent, InputOutput, CopyFromParent, CWEventMask, &swa);
    XMapWindow(display, window);
    XStoreName(display, window, "OpenGL Window");

    GLXContext glc = CreateGLContext(display, window);
    glXMakeCurrent(display, window, glc);

    XEvent xev;
    while (true) {
        if (XPending(display) > 0) {
            XNextEvent(display, &xev);
            if (xev.type == KeyPress) {
                break;
            }
        }

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glXSwapBuffers(display, window);
    }

    glXMakeCurrent(display, None, nullptr);
    glXDestroyContext(display, glc);
    XDestroyWindow(display, window);
    XCloseDisplay(display);

    return 0;
}

#endif
