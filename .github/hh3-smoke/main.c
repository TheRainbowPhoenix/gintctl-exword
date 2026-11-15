#include <gint/config.h>
#include <gint/display.h>
#include <gint/keyboard.h>

HHK_NAME("gint smoke test")
HHK_DESCRIPTION("Basic fx-CP startup, display and key input")
HHK_AUTHOR("gintctl CI")

int main(void)
{
    dclear(C_WHITE);
    dtext(12, 12, C_BLACK, "gint kernel started");
    dtext(12, 30, C_BLACK, "Press EXIT to leave");
    dupdate();

    while(1) {
        key_event_t ev = getkey();
        if(ev.type == KEYEV_DOWN && ev.key == KEY_EXIT)
            break;
    }
    return 0;
}
