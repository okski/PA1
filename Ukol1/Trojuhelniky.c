#include <stdio.h>
#include <stdlib.h>
	int main()
	{float ax=0, ay=0, bx=0, by=0, cx=0, cy=0, xx=0, xy=0, yx=0, yy=0, zx=0, zy=0;
	printf("Trojuhelnik #1:\n");
	printf("Bod A:\n");
	scanf("%f %f", &ax, &ay);
	if (ax, ay == !(ax, ay))
	 {  printf("Nespravny vstup.\n");
	     return 0;}
	printf("Bod B:\n");
	scanf("%f %f", &bx, &by);
	if (bx, by == !(bx, by))
	 {   printf("Nespravny vstup.\n");
	     return 0;}
	printf("Bod C:\n");
	scanf("%f %f", &cx, &cy);
	if (cx, cy == !(cx, cy))
	 {   printf("Nespravny vstup.\n");
	     return 0;}
	if ((abs(ax-bx)==abs(ax-cx) && abs(ax-cx)==abs(bx-cx) && abs(ax-bx)==abs(bx-cx)) || (abs(ay-by)==abs(ay-cy) && abs(ay-cy)==abs(by-cy) && abs(ay-by)==abs(by-cy)))
		{
		    printf("Body netvori trojuhelnik.");
			return 0;
		}
	printf("Trojuhelnik #2:\n");
	printf("Bod A:\n");
	scanf("%f %f", &xx, &xy);
	if (xx, xy == !(xx, xy))
	 {   printf("Nespravny vstup.\n");
	     return 0;}
	printf("Bod B:\n");
	scanf("%f %f", &yx, &yy);
	if (yx, yy == !(yx, yy))
	 {   printf("Nespravny vstup.\n");
	     return 0;}
	printf("Bod C:\n");
	scanf("%f %f", &zx, &zy);
	if (zx, zy == !(zx, zy))
	 {   printf("Nespravny vstup.\n");
	     return 0;}
	if ((abs(xx-yx)==abs(xx-zx) && abs(xx-zx)==abs(yx-zx) && abs(xx-yx)==abs(yx-zx)) || (abs(xy-yy)==abs(xy-zy) && abs(xy-zy)==abs(yy-zy) && abs(xy-yy)==abs(yy-zy)))
		{
			printf("Body netvori trojuhelnik.");
			return 0;
		}
	}
