/*
Hệ thống chiếu sáng: Điều khiển bật/tắt, độ sáng của đèn trong các phòng.
Hệ thống an ninh: Kích hoạt/vô hiệu hóa báo động, giám sát cảm biến cửa, cảm biến chuyển động.
Hệ thống điều hòa không khí (HVAC): Điều chỉnh nhiệt độ, chế độ hoạt động của máy lạnh/máy sưởi.
typedef struct
{
}brightSystem;

typedef struct
{
}curtainSystem;

typedef struct
{
}securitySystem;

typedef struct
{
}hvacSystem;

typdedef struct
{
}smartHomeFacade;

void activeMorningRoutine()
{
    curtainSystemAction(open);// open vs close
    brightSystemAction(on);// mid, high, off
    securitySystemAction(off); //on, off
    hvacSystemAction(off);//on, off
}
void activeAwayMode()
{
    curtainSystemAction(close);// open vs close
    brightSystemAction(off);// mid, high, off
    securitySystemAction(on); //on, off
    hvacSystemAction(off);//on, off
}
void setMovieNightScene()
{
    curtainSystemAction(close);// open vs close
    brightSystemAction(off);// mid, high, off
    securitySystemAction(on); //on, off
    hvacSystemAction(on);//on, off
}

*/

#include <stdio.h>
#include <stdlib.h>
#include "./inc/smartHomeFacade.h"

int main() 
{
    smartHomeFacade* smartHome = createSmartHomeFacade();

    printf(">>> Activating morning routine...\n");
    activateMorningRoutine(smartHome);
    
    printf("\n>>> Activating away mode...\n");
    activateAwayMode(smartHome);
    
    printf("\n>>> Setting movie night scene...\n");
    setMovieNightScene(smartHome);
    
    printf("\nFreeing allocated memory...\n");
    free(smartHome->brightSystem);
    free(smartHome->curtainSystem);
    free(smartHome->hvacSystem);
    free(smartHome->securitySystem);
    free(smartHome);
    
    return 0;
}

