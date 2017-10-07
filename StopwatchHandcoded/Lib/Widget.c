/*
p * Widget.c
 *
 *  Created on: 21/ott/2015
 *      Author: admim
 */

#include "Widget.h"
#include "WidgetConfig.h"
#include "Event.h"

unsigned char contains(Widget *w, TPoint *point){
	if	((point->x >= w->xl) && (point->x <= w->xl + w->xw) &&
		 (point->y >= w->yt) && (point->y <= w->yt + w->yh)) {
		return 1;
	}
	else
		return 0;
}

unsigned char OnTouch(const Widget ws[], TPoint *press){
	unsigned char i, res;

	res = 0;
	for(i=0; i<NUMWIDGETS && res==0 ; i++) {
		if (ws[i].wt == BUTTONICON) {
			if(contains(&ws[i], press)) {
				SetEvent(biconinfo(&ws[i])->onpress);
 			    res = 1;
 			}
		}
	}
	return res;
}

unsigned char DrawInit(const Widget ws[])
{
	unsigned char i;
	for(i=0; i<NUMWIDGETS; i++) {
		DrawOff(&ws[i]);
	}
	return 1;
}

unsigned char DrawOn(const Widget *w)
{
	char *imgptr = 0;

	switch (w->wt) {
	case BUTTONICON:
		imgptr = biconinfo(w)->iconp;
		break;
	case BACKGROUND:
	case IMAGE:
		imgptr = imginfo(w)->image; //(w)->
		break;
	}
	if (imgptr != 0) {
		LCD_DrawPicture(w->xl, w->yt, w->xw, w->yh, imgptr);
		return 1;
	} else
		return 0;
}

unsigned char DrawOff(const Widget *w)
{
	char *imgptr = 0;

	switch (w->wt) {
	case BUTTONICON:
		imgptr = biconinfo(w)->iconr;
		break;
	case BACKGROUND:
	case IMAGE:
		imgptr = imginfo(w)->image;
		break;
	}
	if (imgptr != 0) {
		LCD_DrawPicture(w->xl, w->yt, w->xw, w->yh, imgptr);
		return 1;
	}
		return 0;
}

unsigned char DrawOn2(const Widget *w)
{
	char *imgptr = 0;

	switch (w->wt) {
	case BUTTONICON:
		imgptr = biconinfo(w)->icon2p;
		break;
	case BACKGROUND:
	case IMAGE:
		imgptr = imginfo(w)->image; //(w)->
		break;
	}
	if (imgptr != 0) {
		LCD_DrawPicture(w->xl, w->yt, w->xw, w->yh, imgptr);
		return 1;
	} else
		return 0;
}

unsigned char DrawOff2(const Widget *w)
{
	char *imgptr = 0;

	switch (w->wt) {
	case BUTTONICON:
		imgptr = biconinfo(w)->icon2r;
		break;
	case BACKGROUND:
	case IMAGE:
		imgptr = imginfo(w)->image;
		break;
	}
	if (imgptr != 0) {
		LCD_DrawPicture(w->xl, w->yt, w->xw, w->yh, imgptr);
		return 1;
	}
		return 0;
}

unsigned char WClear(const Widget *w) {
	char *imgptr = 0;

	if(w->wt == TEXT)
		imgptr = txtinfo(w)->background;
	if(imgptr != 0){
		LCD_DrawPicture(w->xl, w->yt, w->xw, w->yh, imgptr);
		return 1;
	}
	return 0;
}

unsigned char WErase(const Widget *w) {
	if (w->wt == BACKTEXT) {
		LCD_DrawPicture(w->xl, w->yt, w->xw, w->yh, backinfo(w)->background);
		return 1;
	} else
		return 0;
}

unsigned char WPrint(const Widget *w, char *s)
{
	if (w->wt == TEXT || w->wt == BACKTEXT) {
		LCD_SetTextColor(txtinfo(w)->color);
		LCD_SetFont(txtinfo(w)->font);
		LCD_DisplayStringXY(w->xl, w->yt, s);
		return 1;
	} else
		return 0;
}





