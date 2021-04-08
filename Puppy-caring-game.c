#include<stdio.h>
#include <windows.h>//gotoxy 함수를 쓰기위한 헤더파일(gotoxy함수:콘솔 화면의 특정 위치로 커서를 옴겨둔후에, 그 곳에서부터 출력하는 함수)
#include<stdlib.h> 
#include<conio.h>
#include<time.h> //랜덤함수 쓰기위한 헤더파일
#include <process.h> //Thread 쓰기위한 헤더파일


void start_game();//strat_game함수선언
void check_score();//check_score함수선언
int opt1=1/*Choose while문 처음에 들어가기 하기 위해서 초기화*/,opt2,opt3,opt4,love=0,power=0,pretty=0,train=0,result;
int time_count1=0, time_count2=0, time_count3=0, time_count4=0;//스레드함수 변수값

unsigned __stdcall Thread(void *arg) //스레드 함수
{
   while(1)//반복을 위해 while문
    {
       Sleep(1000);//1000=1초
     time_count1++;//시간 증가
     time_count2++;//시간 증가
     time_count3++;//시간 증가
     time_count4++;//시간 증가
      if(time_count1==59){
       love-=3;//59초후 친밀도 3감소
            printf("\n친밀도가 3떨어졌어요. 놀아주세요!\n");
          time_count1= 0;//시간지남 0으로 초기화
         }

    else if(time_count2==83){
         power-=4;//83초후 힘 4감소
         printf("\n힘이 4떨어졌어요. 밥을 주세요!\n");
          time_count2= 0;//시간지남 0으로 초기화
      }
    else if(time_count3==113){
      train-=5;//113초후 훈련점수 5감소
          printf("\n훈련점수가 5떨어졌어요. 훈련해주세요!\n");
          time_count3= 0;//시간지남 0으로 초기화
      }
   else if(time_count4==900){//900초후에 게임종료
      system("cls");//창 깨끗하게
      printf("\n강아지 돌보기 게임이 종료되었어요! 감사합니다~\n");
      check_score();//점수 스코어 출력
   }
 }
}
void gotoxy(int x, int y)//좌표설정
{
   COORD Pos;
   Pos.X = x;
   Pos.Y = y; //원하는 콘솔 커서 좌표를 담은 (x : 가로축, y : 세로축) COORD 구조체 변수를 생성
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
   //SetConsoleCursorPosition 함수에,출력위치를 정해주고,위치를 정해주면 커서가 이동
   //핸들:OS 내부에서 관리하는 자료구조
   //GetStdHandle(STD_OUTPUT_HANDLE):표준콘솔 출력 핸들값
   //Pos:위치값
}

void MeunPrint()
{
   gotoxy(50,4); printf("< 강 아 지   돌 보 기>\n");//좌표 입력
   gotoxy(50,5); printf("      ____________\n");
   gotoxy(50,6); printf("    _-            -_\n");
   gotoxy(50,7); printf("   l               ㅣ\n");
   gotoxy(50,8); printf("  ㅣ ===      ===   l \n");
   gotoxy(50,9); printf(" ㅣ   o        o   l ㅣ \n");
   gotoxy(50,10); printf("ㅣ        ㅁ       l  ㅣ\n");
   gotoxy(50,11); printf("ㅣ ㅣ＂   ㅣ    ＂ l  ㅣ\n");
   gotoxy(50,12); printf("ㅣ_ㅣ     ∇      ㅣ__ㅣ\n");
   gotoxy(50,13); printf("    ㄴ____________」\n");
   gotoxy(50,14); printf("       l         ㅣ\n");
   gotoxy(50,15); printf("       l l  l     ㅣ \n");
   gotoxy(50,16); printf("       l l  l      ㅣ\n");
   gotoxy(50,17); printf("       l l  l    (  l_____ \n");
   gotoxy(50,18); printf("      E__E__l___E___l-----l\n");   
   gotoxy(53,20); printf("-----메뉴-----\n");
   gotoxy(53,21); printf("1.게 임 시 작 \n");
   gotoxy(53,22); printf("2.게 임 종 료 \n");
   gotoxy(53,23); printf("3.현 재 시 간 \n");
   gotoxy(53,24); printf("--------------\n");
}
void Estart1()//시작 이모티콘1
{
   gotoxy(50,4); printf("     ♥    ____________\n");
   gotoxy(50,5); printf("         _-            -\n");
   gotoxy(50,6); printf("        l               ㅣ ♡\n");
   gotoxy(50,7); printf("      ㅣ   ⊙       ⊙  l ㅣ \n");
   gotoxy(50,8); printf("     ㅣ        ㅁ       l  ㅣ\n");
   gotoxy(50,9); printf("   ♡ㅣ ㅣ＂   ㅣ    ＂ l  ㅣ\n");
   gotoxy(50,10); printf("     ㅣ_ㅣ     ∇      ㅣ__ㅣ♥    \n");
   gotoxy(50,11); printf("  ______ㄴ____________」______  \n");
   gotoxy(50,12); printf("∈_______               ______∋\n");
   gotoxy(50,13); printf("         l             l\n");
   gotoxy(50,14); printf("         l             l\n");
   gotoxy(50,15); printf("         l             l\n");
   gotoxy(50,16); printf("         l             l\n");
   gotoxy(50,17); printf("         l  _________  l\n");
   gotoxy(50,18); printf("         l l         l l\n");
   gotoxy(50,19); printf("         l l         l l\n");   
   gotoxy(50,20); printf("__________Ｗ_________Ｗ________\n");

}

void Estart2()//시작 이모티콘2
   {
   gotoxy(50,2); printf("           ____________\n");
   gotoxy(50,3); printf("   ♡    _-            ㄱ\n");
   gotoxy(50,4); printf("        l                ㅣ  \n");
   gotoxy(50,5); printf("      ㅣ   ⊙       ⊙  l ㅣ♥ \n");
   gotoxy(50,6); printf("     ㅣ        ㅁ       l  ㅣ\n");
   gotoxy(50,7); printf(" ♥  ㅣ ㅣ＂   ㅣ    ＂ l  ㅣ\n");
   gotoxy(50,8); printf("     ㅣ_ㅣ     ∇      ㅣ__ㅣ  ♡  \n");
   gotoxy(50,9); printf("  ______ㄴ____________」______  \n");
   gotoxy(50,10); printf("∈_______               ______∋\n");
   gotoxy(50,11); printf("         l             l\n");
   gotoxy(50,12); printf("         l             l\n");
   gotoxy(50,13); printf("         l             l\n");
   gotoxy(50,14); printf("         l             l\n");
   gotoxy(50,15); printf("     ____l             l_____\n");
   gotoxy(50,16); printf("  ∈________________________∋\n");
   gotoxy(50,20); printf("_______________________________\n");

}

void Eend1()//끝남 이모티콘1
{
   system("cls");//화면 깨끗하게
    gotoxy(50,4);printf("          ____________\n");     
    gotoxy(50,5); printf("     ☆ _-            -_\n");
    gotoxy(50,6); printf("       l               ㅣ\n");
    gotoxy(50,7); printf("      ㅣ ===      ===   l  ★\n");
    gotoxy(50,8); printf("     ㅣ   ㅅ       ㅅ  l ㅣ \n");
    gotoxy(50,9); printf("    ㅣ        ㅁ       l  ㅣ   ☆\n");
    gotoxy(50,10); printf("    ㅣ ㅣ＂   ㅣ    ＂ l  ㅣ\n");
    gotoxy(50,11); printf("★  ㅣ_ㅣ     ∇      ㅣ__ㅣ     \n");        
    gotoxy(50,12); printf("  ______ㄴ____________」______        \n"); 
    gotoxy(50,13); printf("∈_______               ______∋\n");
    gotoxy(50,14); printf("        l             l\n");
    gotoxy(50,15); printf("        l             l     \n");                          
    gotoxy(50,16); printf("        l             l         \n");               
    gotoxy(50,17); printf("        l             l_____\n");
    gotoxy(50,18); printf("        l  _________________∋\n");
    gotoxy(50,19); printf("        l l   \n");
    gotoxy(50,20); printf("        l l\n");
    gotoxy(50,21); printf("        Ｗ\n");
}


void Eend2()//끝남 이모티콘2
   {
   gotoxy(50,4); printf("          ____________\n");     
    gotoxy(50,5); printf("     ★ _-            -_\n");
    gotoxy(50,6); printf("       l               ㅣ\n");
    gotoxy(50,7); printf("      ㅣ ===      ===   l  ☆\n");
    gotoxy(50,8); printf("     ㅣ   ㅅ       ㅅ  l ㅣ \n");
    gotoxy(50,9); printf("    ㅣ        ㅁ       l  ㅣ   ★\n");
    gotoxy(50,10); printf("    ㅣ ㅣ＂   ㅣ    ＂ l  ㅣ\n");
    gotoxy(50,11); printf("☆  ㅣ_ㅣ     ∇      ㅣ__ㅣ     \n");        
    gotoxy(50,12); printf("  ______ㄴ____________」______        \n"); 
    gotoxy(50,13); printf("∈_______               ______∋\n");
    gotoxy(50,14); printf("         l             l\n");
    gotoxy(50,15); printf("         l             l     \n");                          
    gotoxy(50,16); printf("         l             l         \n");               
    gotoxy(50,17); printf("    _____l             l\n");
    gotoxy(50,18); printf("  ∈_________________  l\n");
    gotoxy(50,19); printf("                     l l   \n");
    gotoxy(50,20); printf("                     l l\n");
    gotoxy(50,21); printf("                      Ｗ\n");
}

void Eplay()//공놀이 이모티콘
{
   gotoxy(30,4); printf("                      ____________     \n");
   gotoxy(30,5); printf("                    _-            -_\n");
   gotoxy(30,6); printf("                   l               ㅣ\n");
   gotoxy(30,7); printf("                  ㅣ ===      ===   l \n");
   gotoxy(30,8); printf("                 ㅣ   ⊙       ⊙  l ㅣ\n");
   gotoxy(30,9); printf("                ㅣ        ㅁ       l  ㅣ\n");
   gotoxy(30,10); printf("                ㅣ ㅣ＂   ㅣ    ＂ l  ㅣ\n"); 
   gotoxy(30,11); printf("                ㅣ_ㅣ     ●      ㅣ__ㅣ\n");
   gotoxy(30,12); printf("              ______ㄴ___//_______」______\n");
   gotoxy(30,13); printf("            ∈_______   //          ______∋\n");
   gotoxy(30,14); printf("                    l             l\n");
   gotoxy(30,15); printf("                    l             l\n");
   gotoxy(30,16); printf("                    l             l\n");   
   gotoxy(33,17); printf("                 l             l\n");
   gotoxy(33,18); printf("             ____l             l_____\n");
   gotoxy(33,19); printf("           ∈________________________∋\n");
   gotoxy(33,20); printf("\n");
   gotoxy(33,21); printf("\n");
   gotoxy(33,22); printf("          ______________________________\n");        
}

void Eplaydisk()//원반던지기 이모티콘
{
   gotoxy(30,4); printf("                      ____________     \n");
   gotoxy(30,5); printf("                    _-            -_\n");
   gotoxy(30,6); printf("                   l               ㅣ\n");
   gotoxy(30,7); printf("                  ㅣ ===      ===   l  \n");
   gotoxy(30,8); printf("                 ㅣ   ⊙       ⊙  l ㅣ \n");
   gotoxy(30,9); printf("                ㅣ        ㅁ       l  ㅣ   \n");
   gotoxy(30,10); printf("                ㅣ ㅣ＂   ㅣ    ＂ l  ㅣ\n");
   gotoxy(30,11); printf("                ㅣ_ㅣ     ∇      ㅣ__ㅣ     \n");
   gotoxy(30,12); printf("                   ㄴ____________」    \n");
   gotoxy(30,13); printf("                   ㅣ   _ㅡㅡ_    l\n");
   gotoxy(30,14); printf("                   ㅣ  ㅣ     ㅣ  l\n");
   gotoxy(30,15); printf("                   ㅣ_∋       ∈_ㅣ\n");
   gotoxy(30,16); printf("                    l  l      l   l  \n");   
   gotoxy(30,17); printf("                    l   -ㅡㅡ-    l         \n");
   gotoxy(30,18); printf("                    l  _________  l    \n");
   gotoxy(30,19); printf("                    l l         l l\n");
   gotoxy(30,20); printf("                    l l         l l \n");
   gotoxy(30,21); printf("                     Ｗ          Ｗ \n"); 
}
void Etouch()//쓰다듬기 이모티콘
{
   gotoxy(30,6); printf("                      ____________     \n");
   gotoxy(30,7); printf("                    _-            -_\n");
   gotoxy(30,8); printf("             ♡♥♡l               ㅣ♥♡♥\n");
   gotoxy(30,9); printf("                  ㅣ ===      ===   l \n");
   gotoxy(30,10); printf("                 ㅣ   ♡       ♡  l ㅣ\n");
   gotoxy(30,11); printf("                ㅣ        ㅁ       l  ㅣ\n");
   gotoxy(30,12); printf("                ㅣ ㅣ＂   ㅣ    ＂ l  ㅣ\n"); 
   gotoxy(30,13); printf("                ㅣ_ㅣ     ω      ㅣ__ㅣ\n");
   gotoxy(30,14); printf("                   ㄴ______________」\n");
   gotoxy(30,15); printf("                      l         ㅣ\n");
   gotoxy(30,16); printf("                      l l  l     ㅣ    __ \n");
   gotoxy(30,17); printf("                      l l  l      ㅣ\  / /\n");
   gotoxy(30,18); printf("                      l l  l    (  l_/ /\n");   
   gotoxy(30,19); printf("                     E__E__l___E___l--/\n");
}
void Efoot()//발톱자르는 이모티콘
{
   gotoxy(30,10); printf("l        l        l        l        l        l        l\n");
   gotoxy(30,11); printf("l        l        l        l        l        l        l\n");
   gotoxy(30,12); printf("l   발   l   가   l   락   l   발   l   가   l   락   l\n");
   gotoxy(30,13); printf("l        l        l        l        l        l        l\n");
   gotoxy(30,14); printf(" ㅡㅡㅡㅡ ㅡㅡㅡㅡ ㅡㅡㅡㅡ ㅡㅡㅡㅡ ㅡㅡㅡㅡ ㅡㅡㅡㅡ \n");
   gotoxy(30,15); printf("    ▽       ▽       ▽       ▽       ▽       ▽   깔끔~~☆\n");
}
void Ewalking()//산책하는 이모티콘
{
   gotoxy(15,1); printf("                                          / /      \n");
   gotoxy(15,2); printf("                                         / /      \n");
   gotoxy(15,3); printf("                                        / /      \n");
   gotoxy(15,4); printf("                                       / /      \n");
   gotoxy(15,5); printf("                                      / /      \n");
   gotoxy(15,6); printf("                      ____________   / /      \n");
   gotoxy(15,7); printf("                    _-            -_/ /\n");
   gotoxy(15,8); printf("                   l               ㅣ/\n");
   gotoxy(15,9); printf("                  ㅣ ===      ===   l    ♬♪♩\n");
   gotoxy(15,10); printf("                 ㅣ    o        o  l ㅣ\n");
   gotoxy(15,11); printf("                ㅣ        ㅁ       l  ㅣ\n");
   gotoxy(15,12); printf("                ㅣ ㅣ＂   ㅣ    ＂ l  ㅣ\n"); 
   gotoxy(15,13); printf("                ㅣ_ㅣ     ω      ㅣ__ㅣ\n");
   gotoxy(15,14); printf("                     ㄴ__________」-------_____  \n");
   gotoxy(15,15); printf("                      lΘ               -----l\n");
   gotoxy(15,16); printf("                      l                 l\n");
   gotoxy(15,17); printf("                      l l  l-------l l  l\n");
   gotoxy(15,18); printf("                      l l  l      _l l  l\n");   
   gotoxy(15,19); printf("                     E__E__l     E__E___l\n");
}
void Ecut()//털짜르는 이모티콘
{
   gotoxy(30,6); printf("                      ____________\n");
   gotoxy(30,7); printf("              ◇    _-            -_\n");
   gotoxy(30,8); printf("                   l               ㅣ\n");
   gotoxy(30,9); printf("                  ㅣ ===      ===   l  ◆ \n");
   gotoxy(30,10); printf("                 ㅣ   >        <   l ㅣ\n");
   gotoxy(30,11); printf("                ㅣ        ㅁ       l  ㅣ\n");
   gotoxy(30,12); printf("                ㅣ ㅣ＂   ㅣ    ＂ l  ㅣ\n"); 
   gotoxy(30,13); printf("             ◆ ㅣ_ㅣ     ∇      ㅣ__ㅣ ◇\n");
   gotoxy(30,14); printf("             ______ㄴ____________」______\n");
   gotoxy(30,15); printf("           ∈_______               ______∋\n");
   gotoxy(30,16); printf("              ◆    l             l\n");
   gotoxy(30,17); printf("                    l             l  ◆  \n");
   gotoxy(30,18); printf("                    l             l\n");   
   gotoxy(30,19); printf("            ◇      l             l\n");
   gotoxy(30,20); printf("                    l  _________  l\n");
   gotoxy(30,21); printf("                    l l         l l\n");
   gotoxy(30,22); printf("                    l l         l l\n");
   gotoxy(30,23); printf("                     Ｗ          Ｗ\n");
}
void Efood()//사료먹는 이모티콘
{
   gotoxy(40,6); printf("         ____________     \n");
   gotoxy(40,7); printf("  ♥   _-            -_   ♡\n");
   gotoxy(40,8); printf("       l               ㅣ\n");
   gotoxy(40,9); printf("      ㅣ ===      ===   l  \n");
   gotoxy(40,10); printf("     ㅣ   ∧       ∧  l ㅣ \n");
   gotoxy(40,11); printf("    ㅣ        ㅁ       l  ㅣ   \n");
   gotoxy(40,12); printf("   ㅣ ㅣ＂    ㅣ    ＂  l  ㅣ\n"); 
   gotoxy(40,13); printf("♡ ㅣ_ㅣ     )∇(       ㅣ__ㅣ \n");
   gotoxy(40,14); printf("       ㄴ____________」      \n");
   gotoxy(40,15); printf("       ㅣ   ㅇㅇㅇ    l  ♥\n");
   gotoxy(40,16); printf("      ㅣ  ㅇㅇㅇㅇㅇ  l\n");
   gotoxy(40,17); printf("       ㅣ_∋ 사료 ∈_ㅣ    ♡\n");
   gotoxy(40,18); printf("        l  l      l   l\n");   
   gotoxy(40,19); printf("     ♥ l   -ㅡㅡ-    l\n");
   gotoxy(40,20); printf("        l  _________  l\n");
   gotoxy(40,21); printf("        l l         l l\n");
   gotoxy(40,22); printf("        l l         l l\n");
   gotoxy(40,23); printf("         Ｗ          Ｗ\n");
}
void Ewater()//물먹는 이모티콘
{
   gotoxy(45,6); printf("         ____________     \n");
   gotoxy(45,7); printf("  ♥   _-            -_   ♡\n");
   gotoxy(45,8); printf("       l               ㅣ\n");
   gotoxy(45,9); printf("      ㅣ ===      ===   l  \n");
   gotoxy(45,10); printf("     ㅣ   ∧       ∧  l ㅣ \n");
   gotoxy(45,11); printf("    ㅣ        ㅁ       l  ㅣ   \n");
   gotoxy(45,12); printf("   ㅣ ㅣ＂    ㅣ    ＂  l  ㅣ\n"); 
   gotoxy(45,13); printf("♡ ㅣ_ㅣ     )--(       ㅣ__ㅣ \n");
   gotoxy(45,14); printf("       ㄴ____________」      \n");
   gotoxy(45,15); printf("       ㅣ   ______    l  ♥\n");
   gotoxy(45,16); printf("      ㅣ   l      l    l\n");
   gotoxy(45,17); printf("       ㅣ_∋  물 ∈___ㅣ    ♡\n");
   gotoxy(45,18); printf("        l  l      l   l\n");   
   gotoxy(45,19); printf("     ♥ l   -ㅡㅡ-    l\n");
   gotoxy(45,20); printf("        l  _________  l\n");
   gotoxy(45,21); printf("        l l         l l\n");
   gotoxy(45,22); printf("        l l         l l\n");
   gotoxy(45,23); printf("         Ｗ          Ｗ\n");
}
void Eto()//토하는 이모티콘
{
   gotoxy(30,6); printf("                      ____________\n");
   gotoxy(30,7); printf("                    _-            -_\n");
   gotoxy(30,8); printf("                   l               ㅣ\n");
   gotoxy(30,9); printf("                  ㅣ ===      ===    l\n");
   gotoxy(30,10); printf("                 ㅣ   X       X    l ㅣ\n");
   gotoxy(30,11); printf("                ㅣ        ㅁ       l  ㅣ\n");
   gotoxy(30,12); printf("                ㅣ ㅣ   __l___     l  ㅣ\n"); 
   gotoxy(30,13); printf("                ㅣ_ㅣ   l_____l   ㅣ__ㅣ\n");
   gotoxy(30,14); printf("                    ㄴ__/@  ^ /___」  \n");
   gotoxy(30,15); printf("                   ㅣ  /$  # /    ㅣ\n");
   gotoxy(30,16); printf("                  ㅣl / %^   /     lㅣ\n");
   gotoxy(30,17); printf("                  ㅣl/\  !  /      lㅣ\n");
   gotoxy(30,18); printf("                  ㅣ/ 3 # /       lㅣ\n");   
   gotoxy(30,19); printf("                   /  ㅗ /        ㅂ\n");
   gotoxy(30,20); printf("                  / )   /________  l\n");
   gotoxy(30,21); printf("                 /? /@ / l       l l\n");
   gotoxy(30,22); printf("                / / / /l l       l l\n");
   gotoxy(30,23); printf("                       Ｗ        Ｗ\n");
}
void Ehumanfood()//사람음식먹는 이모티콘
{
   gotoxy(30,6); printf("                      ____________\n");
   gotoxy(30,7); printf("             ㅠㅠ   _-            -_\n");
   gotoxy(30,8); printf("                   l               ㅣ\n");
   gotoxy(30,9); printf("                  ㅣ ===      ===   l \n");
   gotoxy(30,10); printf("                 ㅣ   ㅠ       ㅠ  l ㅣ\n");
   gotoxy(30,11); printf("                ㅣ    ∬  ㅁ   ∬  l  ㅣ\n");
   gotoxy(30,12); printf("                ㅣ ㅣ ∬  ㅣ   ∬  l  ㅣ\n"); 
   gotoxy(30,13); printf("                ㅣ_ㅣ     ⌒      ㅣ__ㅣ\n");
   gotoxy(30,14); printf("                    ㄴ____________」  \n");
   gotoxy(30,15); printf("                   ㅣ             ㅣ\n");
   gotoxy(30,16); printf("                  ㅣl             lㅣ\n");
   gotoxy(30,17); printf("                  ㅣl             lㅣ\n");
   gotoxy(30,18); printf("                  ㅣl             lㅣ\n");   
   gotoxy(30,19); printf("                  ㅂl             lㅂ\n");
   gotoxy(30,20); printf("                    l  _________  l\n");
   gotoxy(30,21); printf("                    l l         l l\n");
   gotoxy(30,22); printf("                    l l         l l\n");
   gotoxy(30,23); printf("                     Ｗ          Ｗ\n");
}

void Estart()//시작 이모티콘
{
   int time=5;
   Estart1();//시작 이모티콘1
      while(time>00) //time=5이므로 5회 반복
      {
         Sleep(50);//sleep함수란 초 단위로 프로그램 실행을 지연시키는 함수. ()안의숫자/1000초 의미. 0.5초 지연시킴
            time--;//time 값을 1차감
      } //시작 이모티콘1 0.5초씩 5번 실행, 즉 2.5초간 시작 이모티콘1 실행
      system("cls");//실행 화면 지우기
    Estart2();//시작 이모티콘2
     time+=5;//time값 5증가
     while(time>00) //5회 반복
     {
        Sleep(50);//0.5초 지연
        time--;//time 값을 1차감
     }
             system("cls");//실행 화면 지우기
   
}

void Eend()//종료 이모티콘
{
   int time=5;
   Eend1();//종료 이모티콘1
      while(time>00)//5회 반복
      {
         Sleep(50);//0.5초 지연시킴
            time--;//time 값 1차감
      }
     system("cls");//실행 화면 지우기
     Eend2();//종료 이모티콘2
     time+=5;//time값 5증가
     while(time>00) //5회 반복
     {
        Sleep(50);//0.5초 지연시킴
        time--;//time 값 1차감
     }
             system("cls");//실행 화면 지우기
   
}

void play_puppy(){
        printf("놀아주기! 선택하세요\n");
        printf("1.공놀이 2.원반던지기 3.쓰다듬기\n");
        scanf_s("%d", &opt1,sizeof(opt1));//1.2.3.번중 놀아주기 활동 선택
          if (opt1 == 1)//1.공놀이 선택시
          {
            love+=2;//친밀도 2증가
         system("cls");
            printf("친밀도가 2 상승했습니다!\n");
         Eplay();//노는 이모티콘
          }
          else if(opt1 == 2)//2.원반던지기 선택시
          {   
            love+=5;//친밀도 5증가
         system("cls");
            printf("친밀도가 5 상승했습니다!\n");
         Eplaydisk();//원반받는 이모티콘
          }
          else//1번도2번도 아닐시
          {
            love+=4;//친밀도 4증가
         system("cls");
            printf("친밀도가 4 상승했습니다!\n");
         Etouch();//쓰다듬은 이모티콘
          }
}
void management(){
   printf("관리하기! 선택하세요\n");
   printf("1.발톱정리 2. 산책하기 3.털다듬기\n");//1.2.3.중 관리하기 활동 선택
   scanf_s("%d", &opt2,sizeof(opt2));
      if (opt2 == 1)//1.발톱정리 선택시
      {
      pretty+=5;//이쁨 5증가
      system("cls");
      printf("이쁨이 5 상승했습니다!\n");
      Efoot();//발톱자른 이모티콘
      }
      else if (opt2 == 2)//2.산책하기 선택시
      {   
      pretty+=4;//이쁨 4증가
      system("cls");
      printf("이쁨이 4 상승했습니다!\n");
      Ewalking();//산책하는 이모티콘
      }
      else//1.2.번도 아닐시
      {
      pretty+=3;//이쁨 3증가
      system("cls");
      printf("이쁨이 3 상승했습니다!\n");
      Ecut();//털자른 이모티콘
      }
}
void training(){

    int num, answer;//입력변수,정답변수      
         srand(time(NULL));//랜덤함수 난수생성
 
         printf("훈련에 성공하려면 강아지 퀴즈를 맞추세요(OX퀴즈입니다. 맞으면 1번 틀리면 2번을 누르세요.)\n");
         printf("\n");
  
          switch(rand()%11)//11개의수 중 1개 랜덤으로 고름
         {
            case 0://랜덤수 0이 골라졌을때

               printf("강아지는 냄새로 시간을 느낀다\n");
               answer=1;//답은 1번
               scanf_s("%d",&num,sizeof(num));//1.2번중 답 선택해서 입력
               if(answer==num)//정답과 입력한 숫자가 일치할때
               {
                  printf("훈련에 성공했습니다! 5점 획득!\n");
                  train+=5;//훈련점수 5점 증가
               }
      
               else//오답일 시 훈련실패
                  printf("훈련에 실패했습니다,\n");
   
               break;//끝
            case 1://랜덤수 1이 골라졌을때
      
               printf("강아지는 얼굴로 감정을 표현한다\n");
               answer=1;//답은 1번
               scanf_s("%d",&num,sizeof(num));//1.2번중 답 선택해서 입력
               if(answer==num)//정답과 입력한 숫자가 일치할때
               {
                  printf("훈련에 성공했습니다! 5점 획득!\n");
                  train+=5;//훈련점수 5점 증가
               }
               else//오답일 시 훈련실패
                  printf("훈련에 실패했습니다,\n");
               break;//끝
            case 2://랜덤수 2이 골라졌을때
   
               printf("강아지는 사람의 표정을 읽을 수 없다.\n");
               answer=2;//답은 2번
               scanf_s("%d",&num,sizeof(num));//1.2번중 답 선택해서 입력
               if(answer==num)//정답과 입력한 숫자가 일치할때
               {
                  printf("훈련에 성공했습니다! 5점 획득!\n");
                  train+=5;//훈련점수 5점 증가
               }
               else//오답일 시 훈련실패
                  printf("훈련에 실패했습니다,\n");
               break;//끝
            case 3://랜덤수 3이 골라졌을때
   
               printf("강아지는 남자보다 여자를 더 좋아한다.\n");
               answer=1;//답은 1번
                scanf_s("%d",&num,sizeof(num));//1.2번중 답 선택해서 입력
               if(answer==num)//정답과 입력한 숫자가 일치할때
               {
                  printf("훈련에 성공했습니다! 5점 획득!\n");
                  train+=5;//훈련점수 5점 증가
               }
               else//오답일 시 훈련실패
                  printf("훈련에 실패했습니다,\n");
               break;//끝
            case 4://랜덤수 4이 골라졌을때
   
               printf("한밤 중에 개가 갑자기 열이 나며 구토를 하면 사람 해열제를 먹여도 된다. \n");
               answer=2;//답은 2번
               scanf_s("%d",&num,sizeof(num));//1.2번중 답 선택해서 입력
               if(answer==num)//정답과 입력한 숫자가 일치할때
               {
                  printf("훈련에 성공했습니다! 5점 획득!\n");
                  train+=5;//훈련점수 5점 증가
               }
            else//오답일 시 훈련실패
               printf("훈련에 실패했습니다,\n");
               break;//끝

            case 5://랜덤수 5이 골라졌을때
   
               printf("필수 예방접종이 끝나지 않아도 산책을 시켜줘야 한다.\n ");
               answer=1;//답은 1번
                scanf_s("%d",&num,sizeof(num));//1.2번중 답 선택해서 입력
               if(answer==num)//정답과 입력한 숫자가 일치할때
               {
                  printf("훈련에 성공했습니다! 5점 획득!\n");
                  train+=5;//훈련점수 5점 증가
               }
               else//오답일 시 훈련실패
                  printf("훈련에 실패했습니다,\n");
               break;//끝
            case 6://랜덤수 6이 골라졌을때
      
               printf("강아지에게 자이리톨은 위험한 음식이다.\n");
               answer=1;//답은 1번
                scanf_s("%d",&num,sizeof(num));//1.2번중 답 선택해서 입력
               if(answer==num)//정답과 입력한 숫자가 일치할때
               {
                  printf("훈련에 성공했습니다! 5점 획득!\n");
                  train+=5;//훈련점수 5점 증가
               }
               else//오답일 시 훈련실패
                  printf("훈련에 실패했습니다,\n");
               break;//끝

            case 7://랜덤수 7이 골라졌을때
   
               printf("반려동물의 목에 방울을 달아주면 좋아한다.\n");
               answer=2;//답은 2번
                scanf_s("%d",&num,sizeof(num));//1.2번중 답 선택해서 입력
               if(answer==num)//정답과 입력한 숫자가 일치할때
               {
                  printf("훈련에 성공했습니다! 5점 획득!\n");
                  train+=5;//훈련점수 5점 증가
               }
               else//오답일 시 훈련실패
                  printf("훈련에 실패했습니다,\n");
               break;//끝
            case 8://랜덤수 8이 골라졌을때
   
               printf("개는 기분이 나쁠 때도 꼬리를 흔들 수 있다.\n");
               answer=1;//답은 1번
                scanf_s("%d",&num,sizeof(num));//1.2번중 답 선택해서 입력
               if(answer==num)//정답과 입력한 숫자가 일치할때
               {
                  printf("훈련에 성공했습니다! 5점 획득!\n");
                  train+=5;//훈련점수 5점 증가
               }
               else//오답일 시 훈련실패
                  printf("훈련에 실패했습니다,\n");
               break;//끝

            case 9://랜덤수 9이 골라졌을때
   
               printf("개는 먹는 것보다 산책을 더 좋아 한다.\n");
               answer=1;//답은 1번
               scanf_s("%d",&num,sizeof(num));//1.2번중 답 선택해서 입력
               if(answer==num)//정답과 입력한 숫자가 일치할때
               {
                  printf("훈련에 성공했습니다! 5점 획득!\n");
                  train+=5;//훈련점수 5점 증가
               }
               else//오답일 시 훈련실패
                  printf("훈련에 실패했습니다,\n");
               break;//끝
            case 10://랜덤수 10이 골라졌을때
      
               printf("개는 혀를 내밀고 다니므로 더위에 강하다.\n");
               answer=2;//답은 2번
               scanf_s("%d",&num,sizeof(num));//1.2번중 답 선택해서 입력
               if(answer==num)//정답과 입력한 숫자가 일치할때
               {
                  printf("훈련에 성공했습니다! 5점 획득!\n");
                  train+=5;//훈련점수 5점 증가
               }
               else//오답일 시 훈련실패
                  printf("훈련에 실패했습니다,\n");
               break;//끝

            case 11://랜덤수 11이 골라졌을때
         
               printf("개는 코를 만져주면 좋아한다.\n");
               answer=2;//답은 2번
                scanf_s("%d",&num,sizeof(num));//1.2번중 답 선택해서 입력
               if(answer==num)//정답과 입력한 숫자가 일치할때
               {
                  printf("훈련에 성공했습니다! 5점 획득!\n");
                  train+=5;//훈련점수 5점 증가
               }
               else//오답일 시 훈련실패
               printf("훈련에 실패했습니다,\n");
               break;
            default://아무것도아닐시
               break;//끝
      
            }//switch문 종료
         
}//training함수 종료
void Feeding(){
        printf("먹이주기! 선택하세요\n"); 
        printf("1.사료 2.물 3.초콜릿 4.오늘 먹다남긴 저녁\n");
        scanf_s("%d", &opt4,sizeof(opt4));//1,2,3,4 중 먹이주기 활동 선택
          if (opt4 ==1)//1.사료 선택시
          {
            power+=5;// 힘 5증가
         system("cls");
            printf("힘이 5 상승했습니다!\n");
         Efood();//사료먹는 이모티콘
          }
          else if (opt4 ==2)//2.물 선택시
          {   
            power+=3;// 힘 3증가
         system("cls");
            printf("힘이 3 상승했습니다!\n");
         Ewater();//물먹는 이모티콘
          }
          else if (opt4 ==3)//3. 초콜릿 선택시
          {
            power-=10;//힘 10감소
         system("cls");
            printf("강아지가 토를합니다!ㅠㅠ힘이 10감소했어요.\n");
         Eto();//토하는 이모티콘
          }
          else//1.2.3 외의 값 선택
          {
            power-=4;//힘 4감소
         system("cls");
            printf("강아지에게는 사료를 주세요!힘이 4감소했어요.\n");
         Ehumanfood();//사람음식먹은 이모티콘
          }
}
void end_game(){//게임을 끝낼 시
   Eend();
   Eend();
   opt1 = 0;//0 입력시
   check_score();//애견점수 확인할 수 있는 함수로 이동
}
void check_score(){//애견점수 보여주는 함수
   printf("당신의 애견 점수는?\n");
   result = love + pretty + train + power;//애견점수=모든점수 더한것
   printf("친밀도 %d! 이쁨 %d! 훈련점수 %d! 힘 %d!\n\n", love, pretty, train, power);

   
      if(result==0)//애견점수가 0일 경우
     {
        printf("아직 시작을 안한것 같은데 !!? 열심히 했는데도 0점일리가 없자나 ! \n");
     }
     else if(result<0)//애견점수가 0보다 작을 경우
      {
         printf("넌 강아지 키울 자격이 없어!\n");
      }
      else if(result>=1 && result<30)//애견점수가 1이상이고 30보다 작을 경우
      {
         printf("아프지않게 돌봐줘서 고마워\n");
      }
      else if(result>=30)//애견점수가 30이상일 경우
         printf("강아지 키우는 데에 일가견이 있구나! 너를 펫샵에 넣어주도록 할게!\n");
}
void Choose()
{
   
   _beginthreadex(NULL, 0, Thread, 0, 0,NULL);//스레드 시작
   while(opt1){ //opt1반복
      printf("1. 놀아주기 2. 관리하기 3. 훈련 4. 먹이주기 5.점수확인 6.이전메뉴 0. 종료\n"); 
      printf("활동선택?: ");
      scanf_s("%d", &opt1,sizeof(opt1));// 1,2,3,4,5,6,0 중 활동 선택

      switch(opt1)
      {
      case 1://1. 놀아주기 선택 시
        play_puppy();//놀아주기 함수로 이동
        break;
      case 2://2. 관리하기 선택 시
        management();//관리하기 함수로 이동
        break;
      case 3://3. 훈련 선택 시
       training();
        break;
      case 4://4. 먹이주기 선택 시
        Feeding();
        break;
     case 5://5. 점수확인 선택 시
        check_score();
         break;
     case 6://6. 이전메뉴 선택 시
        start_game();
         break;
      case 0://0. 종료 선택 시
        end_game();
         break;
      default://아무것도 아닐시
        printf("숫자를 잘못 입력했어요! 다시 입력하세요! \n");
      }//switch문 종료
   }//while문 종료

}// Choose함수 종료

void Infor()
{
   char name[20];//이름변수
   int a;//시작,종료 입력 변수
   scanf_s("%s",name,sizeof(name));//이름입력
   printf("%s아(야)!! 나 여행을 갔다 오기로 했어. \n요즘 인생이 너무 힘들거든. \n3일 동안 내 강아지 야삐를 돌봐줘. \n야삐가 나에게 엄청 소중한 존재인거 잘알지? \n돌아와서 야삐 상태를 보고 너의 애견 점수를 측정해 줄게. \n%s아(야) 우리 야삐 잘 부탁해!!\n", name, name);
    printf("\n");
    printf("시작하려면 1을 누르고, 종료하려면 2를 누르세요\n");
    scanf_s("%d", &a,sizeof(a));//1번 누르면 시작, 2번 누르면 종료
   switch(a)
   {
   case 1://1번 누를시
      system("cls");//창 깨끗하게
     Estart();
     Estart();
      Choose();//Choose함수로 이동
      break;//끝
   case 2://2번 누를시
     printf("종료하시려면 Enter를 누르세요.\n");
      break;//끝
   }

}

void Name()
{
   int num;//
   printf("이름을 입력하세요 : ");
   scanf("%d" , &num);
   system("cls");//창 깨끗하게
   Infor();//Infor함수로 이동
}
void start_game(){//게임시작
   int select;
   system("cls");
   MeunPrint();//메뉴 출력
   scanf("%d", &select);//메뉴 1.2.3.번 중 선택
   switch(select)
   {
   case 1://1번 선택시
      system("cls");//창 깨끗하게
      Name();//Name 함수로 이동
      break;//끝
   case 2://2번 선택시
     system("cls");//창 깨끗하게
      printf("게임을 종료합니다.\n");
      break;//종료
   case 3://3번 선택시
     system("cls");//창 깨끗하게
   { 
      time_t now;
      struct tm *d;

      while(!kbhit())//아무키나 누르면 메뉴로 돌아가게
      {
         system("cls");//창 깨끗하게
         now=time(NULL);
         d=localtime(&now);
         printf("현재날짜와시간: %s\n", asctime(d));
       }
      system("cls");//창 깨끗하게
      start_game();
   }//case3 종료

   default://아무것도 아닐시
      break;//끝
   }//switch끝
}//strat_game함수 끝
   
int main(void)
{
  start_game();//게임시작
}
