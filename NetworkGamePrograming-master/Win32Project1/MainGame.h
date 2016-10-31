#pragma once
#include "MyHeader.h"
#include "Obj.h"
#include"Player.h"
#include"DoubleBuffering.h"
#include "Collision.h"

class CMainGame
{
	HDC m_hdc;
	CDoubleBuffering m_doubleBuffering;
	CPlayer	 m_player	;
	CBall m_ball;
	Collision m_collision;

public:
	CMainGame();
	~CMainGame();
	void Initialize();
	void Progress();
	void Render();
	void Release();

/* 
[2016/09/02 18��57�� 
�ۼ��� : �ڿ���(dygks910910@daum.net)]
����:MouseInputMessage()���콺 �Է�ó���Լ�.
*/
	void MouseInputProcessing(const MSG& msg);
	void KeyboardInputProcessing(const MSG	& msg);
	void GameTimer(const MSG& msg);
};