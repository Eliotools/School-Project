int rush (int x, int y)
{
    int comeback_x = x;
    int i = 0;
    if (x > 0 && y > 0) {
        x -= 2;
        y -= 2;
        line_u(x, y, comeback_x);
        collum(x, y, comeback_x);
        write(1, "\n", 1);
        if (y > -1 && x > -1)
            line_d(x, y, comeback_x);
    } else {
        write(1, "Invalid size\n", 16);
        }

}
int line_u (int x, int y, int comeback_x)
{
    if (y == -1 != x == -1)
        for (x ; x > -2; --x)
            write (1, "*",1);
    else if ( x > -1) {
        if ( y != -1 )
            write (1, "/", 1);
        if ( y == -1)
            x += 2;
        while (x > 0){
            write (1, "*", 1);
            x--;
        }
        if (x > -1)
            if (y != -1)
                write (1, "\\", 1);
    }
    x = comeback_x - 2;
}
int line_d(int x, int y, int comeback_x)
{
    x = comeback_x - 2;
    write (1, "\\", 1);
    while (x > 0) {
        write (1, "*", 1);
        x--;
        x = comeback_x - 2;
    }
    if (x > -1) {
        write (1, "/", 1);
        write (1, "\n", 1);
    }
}
int collum (int x, int y, int comeback_x)
{
    int y_ = y;
    if (x == -1) {
        for (y ; y > -2; --y){ 
            write (1, "*",1);    
        }
    }
    else if ( y > -1 )
        space_x(x, y, comeback_x);
}
int space_x (int x, int y, int comeback_x)
{
    while ( y > 0) {
        write (1, "\n", 1);
        if (x > -1)
            write (1, "*", 1);
        while (x > 0) {
            write (1, " ", 1);
            x--;
        }
        x = comeback_x - 2;
        write (1, "*", 1);
        y--;
    }
}
int main (void)
{
    rush(0, 10);
    return(0);
}
