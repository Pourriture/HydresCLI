#ifndef HYDRESS_SCREENPART_INCLUDED
#define HYDRESS_SCREENPART_INCLUDED
typedef struct screenCoord screenCoord;

struct screenCoord
{
    int start_x;
    int end_x;
    int start_y;
    int end_y;
    int length_x;
    int length_y;
};

#define screen(arg) \
    (arg).start_x, (arg).end_x, (arg).start_y, (arg).end_y

#define screenlinit(arg, sx, lx, sy, ly) \
    screenCoord arg;        \
    arg.start_x = sx;       \
    arg.end_x = sx + lx;    \
    arg.start_y = sy;       \
    arg.end_y = sy + ly;    \
    arg.length_x = lx;      \
    arg.length_y = ly

#define screencinit(arg, sx, ex, sy, ey) \
    screenCoord arg;        \
    arg.start_x = sx;       \
    arg.end_x = ex;         \
    arg.start_y = sy;       \
    arg.end_y = ey;         \
    arg.length_x = ex - sx; \
    arg.length_y = ey - ex

#endif // HYDRESS_SCREENPART_INCLUDED
