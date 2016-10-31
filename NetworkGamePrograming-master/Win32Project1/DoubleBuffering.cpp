#include "stdafx.h"
#include "DoubleBuffering.h"


CDoubleBuffering::CDoubleBuffering()
{
}


CDoubleBuffering::~CDoubleBuffering()
{
}
/* 
[2016/09/02 3��36�� 
�ۼ��� : �ڿ���(dygks910910@daum.net)]
����:�ʱ�ȭ�ܰ�
*/
void CDoubleBuffering::Initialize(HDC hdc, RECT clientRect)
{
	m_clientRect =  clientRect;
	m_memDC = CreateCompatibleDC(hdc);
	HBITMAP oldbitmap = CreateCompatibleBitmap(m_memDC, clientRect.right, clientRect.bottom);
	m_hPreBit = (HBITMAP)SelectObject(m_memDC, oldbitmap);
	FillRect(m_memDC, &clientRect, GetSysColorBrush(COLOR_WINDOW));

}
