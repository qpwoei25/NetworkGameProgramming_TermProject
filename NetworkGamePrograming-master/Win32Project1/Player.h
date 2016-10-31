#pragma once
#include "Ball.h"
/* 
[2016/09/03 18��27�� 
�ۼ��� : �ڿ���(dygks910910@daum.net)]
����:�� �÷��̾ �ۼ��Ұ���.������Ÿ������ �����д�.
*/
/* 
[2016/09/04 18��11�� 
�ۼ��� : �ڿ���(dygks910910@daum.net)]
����:CObj�� �ִ� �Լ����� �貸�Դ�. �����׸��� ����.MoveUp,Down�Լ��� �߰��� MainGame���� ��Ʈ���Ұ���.
*/
/*
2016 / 10 / 27 / 15:36
�ۼ���:�ڿ���(dygks910910@daum.net)
����:	moveup,moveDown �Լ��� �����ϰ� ������ �߰�.������ �߰��ϰ� ������ �Լ��� �ϳ��� ��ħ.
*/
/*
2016 / 10 / 27 / 15:46
�ۼ���:�ڿ���(dygks910910@daum.net)
����:�����ϰ� ���� Ŭ���� CBall �� ������ �ڽ�Ŭ������ Player�� �Ѱ�.
*/
class CPlayer :
	public CBall	
{
public:
	CPlayer();
	~CPlayer();
	virtual void Initialize(const CVector2& pos, const float& size, const float& speed) ;
	virtual void Progress() ;
	virtual void Render(HDC) ;
	virtual void Release();
	/* 
	[2016/09/04 18��18�� 
	�ۼ��� : �ڿ���(dygks910910@daum.net)]
	����:�� �Լ��� player�� ��Ʈ��.
	*/
	void MoveToMousePos(const CVector2& MousePos, char* p1);

};

