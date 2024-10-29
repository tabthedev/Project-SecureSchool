#include <cstdlib>
#include <time.h>
#include <Windows.h>
#include <thread>
#include <stdio.h>

int main() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	int i = 0;
	while (true) {
		Sleep(50);
		time_t seconds = time(NULL);
		int seconds_int = (int)seconds + 32400;
		int secFromDay = seconds_int % 86400;
		int secFromWeek = (seconds_int + 345600) % 604800;

		(518400 > secFromWeek && secFromWeek >= 0) ? printf("t1 ") : printf("f1 ");
		(34980 > secFromDay && secFromDay > 34500) ? printf("t2\n") : printf("f2\n");
		printf("%i  ..  %i\n",secFromDay, secFromWeek);


		if (
			(518400 > secFromWeek && secFromWeek >= 0) // 월~금
			
			&&

			((34980 > secFromDay && secFromDay > 34500) || //1교시~2교시 사이 8분 -> 예비종 제외
				(38280 > secFromDay && secFromDay > 37800) || //2~3 사이 8분 -> ''
				(41580 > secFromDay && secFromDay > 41100) || //3~4 사이 8분
				(47280 > secFromDay && secFromDay > 44400) || //4~5 사이 48분
				(50580 > secFromDay && secFromDay > 50100)) //5~6 사이 10분
			)
		{
			printf("ac\n");
			i++;
			i % 2 == 0 ? system("taskkill /f /im chrome.exe && PowerShell -Command \"Add-Type -AssemblyName PresentationFramework;[System.Windows.MessageBox]::Show('담임선생님과 정보부장의 허락 없이는 실행할 수 없습니다.', '週中 쉬는 시간 감지됨', 'Ok','Error')\"") : system("taskkill /f /im msedge.exe && PowerShell -Command \"Add-Type -AssemblyName PresentationFramework;[System.Windows.MessageBox]::Show('담임선생님과 정보부장의 허락 없이는 실행할 수 없습니다.', '週中 쉬는 시간 감지됨', 'Ok','Error')\"");
		}
	}
	return 0;
}
