#pragma once
/* 
[2016/09/02 3��35�� 
�ۼ��� : �ڿ���(dygks910910@daum.net)]
���泻��:������۸�
��������:
*/
class CDoubleBuffering
{
private:
	HDC m_memDC;
	HBITMAP m_hPreBit;
	RECT m_clientRect;
public:
	CDoubleBuffering();
	~CDoubleBuffering();
public:
	HDC GetmemDC() { return m_memDC; }
	void Initialize(HDC hdc,RECT clientRect);
	template<class obj>
	void WriteToBackBuffer(obj* object);
	/* 
	[2016/09/02 3��35�� 
	�ۼ��� : �ڿ���(dygks910910@daum.net)]
	����:������۷� present���� ������� �ʱ�ȭ������� �Ѵ�.
	*/
	void Present(HDC hdc)
	{
		BitBlt(hdc, 0, 0, m_clientRect.right, m_clientRect.bottom,m_memDC, 0, 0, SRCCOPY);
		Initialize(hdc, m_clientRect);
	}
};
//obj��ӵȰ͵鸸 ������ ����.
template<class obj>
inline void CDoubleBuffering::WriteToBackBuffer(obj * pBbject)
{
	pBbject->Render(m_memDC);
}
