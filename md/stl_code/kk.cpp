#include <iostream>
#include <windows.h>

void mouseClick(int x, int y, DWORD flag) {
    SetCursorPos(x, y); // 移动鼠标到指定位置
    mouse_event(flag, 0, 0, 0, 0); // 触发鼠标事件
}

int main() {
    const DWORD LEFTDOWN = MOUSEEVENTF_LEFTDOWN;
    const DWORD LEFTUP = MOUSEEVENTF_LEFTUP;
    const DWORD RIGHTDOWN = MOUSEEVENTF_RIGHTDOWN;
    const DWORD RIGHTUP = MOUSEEVENTF_RIGHTUP;

    for (int i = 0; i < 5000; ++i) { // 循环5000次
        Sleep(2000); // 延时 2000 毫秒
        // 检查q键是否被按下
        if (GetAsyncKeyState('Q') & 0x8000) {
            std::cout << "检测到q键按下，退出循环。" << std::endl;
            break; // 跳出循环
        }

        std::cout << "执行第 " << (i + 1) << " 次操作..." << std::endl;
        std::cout.flush();

        // 操作步骤
        std::cout << "(鼠标)移动到(202, 954)" << std::endl;
        mouseClick(202, 954, RIGHTDOWN); // 右键按下
        mouseClick(202, 954, RIGHTUP); // 右键抬起，1次

        std::cout << "(鼠标)移动到(398, 307)" << std::endl;
        mouseClick(398, 307, LEFTDOWN); // 左键按下
        mouseClick(398, 307, LEFTUP); // 左键抬起，1次

        Sleep(2000); // 延时 2000 毫秒

        Sleep(10000); // 延时 10000 毫秒

        std::cout << "(鼠标)移动到(967, 815)" << std::endl;
        mouseClick(967, 815, LEFTDOWN); // 左键按下
        mouseClick(967, 815, LEFTUP); // 左键抬起
        mouseClick(967, 815, LEFTDOWN); // 左键再次按下
        mouseClick(967, 815, LEFTUP); // 左键再次抬起，2次

        Sleep(8000); // 延时 8000 毫秒

        std::cout << "(鼠标)移动到(1157, 119)" << std::endl;
        mouseClick(1157, 119, LEFTDOWN); // 左键按下
        mouseClick(1157, 119, LEFTUP); // 左键抬起
        mouseClick(1157, 119, LEFTDOWN); // 左键再次按下
        mouseClick(1157, 119, LEFTUP); // 左键再次抬起，2次
    }

    std::cout << "所有操作执行完毕！" << std::endl;
    
    return 0;
}
