#include "splashkit.h"
using namespace std;

#define MAX_RADIUS 200
#define MIN_RADIUS 10

int main()
{
    double x;
    double y;
    double radius;
    x = 400;
    y = 300;
    radius = 105;
    color circle_color = COLOR_YELLOW;

    open_window("Circle moving by Jennifer", 800, 600);

    y = screen_height() / 2;

    while (not quit_requested())
    {
        process_events();

        if (key_typed(A_KEY))
        {
            circle_color = random_color();
        }
        if (key_down(DOWN_KEY) && y < screen_height() - radius)
        {
            y = y + 3;
        }
        if (key_down(UP_KEY) && y > radius)
        {
            y = y - 3;
        }
        if (key_down(EQUALS_KEY) && radius < MAX_RADIUS)
        {
            radius = radius + 2;
        }
        if (key_down(MINUS_KEY) && radius > MIN_RADIUS)
        {
            radius = radius - 2;
        }
        if (key_down(J_KEY))
        {
            radius = 105;
            x = 400;
            y = 300;
        }

        clear_screen(COLOR_FLORAL_WHITE);
        fill_circle(circle_color, x, y, radius);
        refresh_screen(60);
    }

    return 0;
}

// link for the video : https://d2l.deakin.edu.au/d2l/ext/rp/882859/lti/framedlaunch/e120dab2-1355-47b4-9d02-5491b8a89ec8