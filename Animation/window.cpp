/* Cheptsov Vasiliy, 10-4 class, 02.06.2014 */

#include "../physic.h"

/* Class constructor.
 * ARGUMENTS: None.
 */
tlr::win::win( VOID ) :
  WinW(0), WinH(0), hWndValue(NULL),
  ActiveFlag(FALSE), IsInit(FALSE), IsFullScreen(FALSE),
  hWnd(hWndValue), W(WinW), H(WinH), IsActive(ActiveFlag),
  hInstance(GetModuleHandle(NULL))
{
  /* Register window class */
  WNDCLASS wc;

  wc.style = CS_HREDRAW | CS_VREDRAW;
  /* Additional memory for window pointer store */
  wc.cbWndExtra = sizeof(this);
  wc.cbClsExtra = 0;
  wc.hInstance = hInstance;
  wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
  wc.hCursor = LoadCursor(NULL, IDC_HAND);
  wc.hIcon = LoadIcon(NULL, IDI_INFORMATION);
  wc.lpszMenuName = NULL;

  const CHAR MyClassName[] = "MyWindowClassName";
  wc.lpszClassName = MyClassName;
  wc.lpfnWndProc = WinFunc;
  RegisterClass(&wc);

  hWndValue =
    CreateWindow(MyClassName, "Hello everybody",
      WS_OVERLAPPEDWINDOW | WS_VISIBLE,
      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
      NULL, NULL, hInstance, this);

  ShowWindow(hWnd, SW_SHOWNORMAL);
  UpdateWindow(hWnd);
  PostMessage(hWnd, WM_TIMER, InitializationTimer, 0);
} /* End of 'tlr::win::win' constructor */

/* Main message loop function.
 * ARGUMENTS: None.
 * RETURNS: None.
 */
VOID tlr::win::Run( VOID )
{
  MSG msg;

  /* Main message loop */
  while (TRUE)
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
      /* Exit from loop if quit message came */
      if (msg.message == WM_QUIT)
        break;
      /* Dispatch message to appropriate window */
      DispatchMessage(&msg);
    }
    else
      if (IsInit)
        InvalidateRect(hWnd, NULL, FALSE);
} /* End of 'tlr::win::Run' function */

/* Exit from main loop function.
 * ARGUMENTS: None.
 * RETURNS: None.
 */
VOID tlr::win::DoExit( VOID )
{
  PostMessage(hWnd, WM_CLOSE, 0, 0);
} /* End of 'tlr::win::DoExit' function */

/* Goto fullscreen mode function.
 * ARGUMENTS:
 *   - full screen flag:
 *       BOOL FullScreenFlag;
 * RETURNS:
 *   (BOOL) old full screen set flag value.
 */
BOOL tlr::win::SetFullScreen( BOOL FullScreenFlag )
{
  RECT rc;
 
  if (IsFullScreen == FullScreenFlag)
    return FullScreenFlag;
  if (FullScreenFlag)
  {
    DWORD Style;
 
    IsFullScreen = TRUE;

    /* Determine what monitor window lies on */
    HMONITOR hMon = MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST);
    MONITORINFOEX mi;
    mi.cbSize = sizeof(mi);
    GetMonitorInfo(hMon, &mi);

    /* Expand window to full screen size */
    GetWindowRect(hWnd, &SaveRC);
 
    /* Old style - one monitor support:
    rc.left = 0;
    rc.top = 0;
    rc.right = GetSystemMetrics(SM_CXSCREEN);
    rc.bottom = GetSystemMetrics(SM_CYSCREEN);
    */
    rc = mi.rcMonitor;
    Style = GetWindowLong(hWnd, GWL_STYLE);
    AdjustWindowRect(&rc, Style, FALSE);
 
    SetWindowPos(hWnd, HWND_TOP, 
      rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top,
      SWP_NOREDRAW | SWP_NOOWNERZORDER | SWP_NOSENDCHANGING);
  }
  else
  {
    /* Restore window size and position */
    IsFullScreen = FALSE;
    SetWindowPos(hWnd, HWND_TOP, 
      SaveRC.left, SaveRC.top,
      SaveRC.right - SaveRC.left, SaveRC.bottom - SaveRC.top,
      SWP_NOOWNERZORDER);
  }
  GetClientRect(hWnd, &rc);
  PostMessage(hWnd, WM_SIZE, 0,
    MAKELONG(rc.right, rc.bottom));
  return !IsFullScreen;
} /* End of 'tlr::win::SetFullScreen' function */

/* Window message handle function.
 * ARGUMENTS:
 *   - window descriptor:
 *       HWND hWnd;
 *   - message number:
 *       UINT Msg;
 *   - message parameter ('word parameter'):
 *       WPARAM wParam;
 *   - message parameter ('long parameter'):
 *       LPARAM lParam;
 * RETURNS:
 *   (LRESULT) - depending on message.
 */
LRESULT CALLBACK tlr::win::WinFunc( HWND hWnd, UINT Msg,
                                     WPARAM wParam, LPARAM lParam )
{
  win *MyWindow;

  if (Msg == WM_CREATE)
  {
    /* Obtain window pointer from create parameters */
    MyWindow = (win *)((CREATESTRUCT *)lParam)->lpCreateParams;
    /* Attach window class to window structure */
    SetWindowLong(hWnd, 0, (DWORD)MyWindow);
    MyWindow->hWndValue = hWnd;
    return MyWindow->OnCreate((CREATESTRUCT *)lParam) ? 0 : -1;
  }
  /* Obtain attached window class */
  if ((MyWindow = (win *)GetWindowLong(hWnd, 0)) != NULL)
    switch (Msg)
    {
    case WM_DESTROY:
      MyWindow->OnDestroy();
      return 0;
    case WM_SIZE:
      MyWindow->OnSize(wParam, (SHORT)LOWORD(lParam), (SHORT)HIWORD(lParam));
      return 0;
    case WM_PAINT:
      MyWindow->OnPaint();
      return 0;
    case WM_TIMER:
      MyWindow->OnTimer(wParam);
      return 0;
    case WM_ACTIVATE:
      MyWindow->OnActivate((UINT)LOWORD(wParam), (HWND)(lParam), (BOOL)HIWORD(wParam));
      return 0;
    case WM_ERASEBKGND:
      return MyWindow->OnEraseBkgnd((HDC)wParam);
    }
  return DefWindowProc(hWnd, Msg, wParam, lParam);
} /* End of 'tlr::win::WinFunc' function */

/* WM_CREATE handle message function.
 * ARGUMENTS:
 *   - window creation paramters pointer:
 *       CREATESTRUCT *CreateStruct;
 * RETURNS:
 *   (BOOL) - FALSE to close the window, TRUE if succeed.
 */
BOOL tlr::win::OnCreate( CREATESTRUCT *CreateStruct )
{
  return TRUE;
} /* End of 'tlr::win::OnCreate' function */

/* WM_DESTROY handle message function.
 * ARGUMENTS: None.
 * RETURNS: None.
 */
VOID tlr::win::OnDestroy( VOID )
{
  /* Call user level deinitialization */
  if (IsInit)
  {
    IsInit = FALSE;
    Close();
  }
  KillTimer(hWnd, 30);
  PostQuitMessage(30);
} /* End of 'tlr::win::OnDestroy' function */

/* WM_SIZE  handle message function.
 * ARGUMENTS:
 *   - window resize reason (see SIZE_***, etc. SIZE_MAXIMIZED):
 *       UINT State;
 *   - new windows width and height:
 *       INT Width, Height;
 * RETURNS: None.
 */
VOID tlr::win::OnSize( UINT State, INT Width, INT Height )
{
  WinW = Width;
  WinH = Height;
  /* Call user level change size notifivcation */
  if (IsInit)
    Resize();
  OnPaint();
} /* End of 'tlr::win::OnSize' function */

/* WM_PAINT  handle message function.
 * ARGUMENTS: None.
 * RETURNS: None.
 */
VOID tlr::win::OnPaint( VOID )
{
  HDC hDC;
  PAINTSTRUCT ps;

  hDC = BeginPaint(hWnd, &ps);
  if (IsInit)
    Paint(hDC);
  EndPaint(hWnd, &ps);
} /* End of 'tlr::win::OnPaint' function */

/* WM_ERASEBKGND handle message function.
 * ARGUMENTS:
 *   - windows context:
 *       HDC hDC;
 * RETURNS:
 *   (BOOL) TRUE if background cleared, else FALSE.
 */
BOOL tlr::win::OnEraseBkgnd( HDC hDC )
{
  if (!IsInit)
    return DefWindowProc(hWnd, WM_ERASEBKGND, (WPARAM)hDC, 0);
  Erase(hDC);
  return FALSE;
} /* End of 'tlr::win::OnEraseBkgnd' function */

/* WM_ACTIVATE window message handle function.
 * ARGUMENTS:
 *   - reason (WA_CLICKACTIVE, WA_ACTIVE or WA_INACTIVE):
 *       UINT Reason;
 *   - handle of active window:
 *       HWND hWndActDeact;
 *   - minimized flag:
 *       BOOL IsMinimized;
 * RETURNS: None.
 */
VOID tlr::win::OnActivate( UINT Reason, HWND hWndActDeact, BOOL IsMinimized )
{
  ActiveFlag = Reason == WA_CLICKACTIVE || Reason == WA_ACTIVE;

  /* Call user level activate handle function */
  if (IsInit)
    Activate();
} /* End of 'tlr::win::OnActivate' function */

/* WM_TIMER handle message function.
 * ARGUMENTS:
 *   - timer identifier:
 *       INT Id;
 * RETURNS:
 *   (BOOL) TRUE if background cleared, else FALSE.
 */
VOID tlr::win::OnTimer( INT Id )
{
  if (Id == InitializationTimer)
  {
    IsInit = TRUE;
    Init();
    Resize();
    InvalidateRect(hWnd, NULL, TRUE);
    if (IsActive)
      Activate();
    SetTimer(hWnd, 30, 30, NULL);
  }
  else
    if (IsInit)
      Timer();
} /* End of 'tlr::win::OnTimer' function */

/* END OF 'window.cpp' FILE */
