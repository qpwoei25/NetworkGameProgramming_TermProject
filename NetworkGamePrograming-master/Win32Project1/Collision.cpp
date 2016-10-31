#include "stdafx.h"
#include "Collision.h"
#include <math.h>
#include <iostream>

Collision::Collision() : beCollision(false) {
	//to do this;
};

Collision::~Collision() {
	//to do this;
};


bool Collision::ifCollision(CPlayer &player, CBall &ball) {
	
	//�� �� ������ �Ÿ��� ���Ͽ� �� �Ÿ��� �ο��� �������� �պ��� ������� �浹�� �Ǵ�
	double nDist;
	double nRadius;

	CVplayerPos = player.GetPosition();
	CVballPos = ball.GetPosition();


	nDist = Distance(CVplayerPos, CVballPos); //�� �� ������ �Ÿ�
	nRadius = player.GetBallSize() + ball.GetBallSize(); //�� ���� �������� ��

	if (nDist <= nRadius) {
		beCollision = true;
		ComputeCollision(player, ball);
		return beCollision;
	}

	else
		return beCollision;
	
};

//�� �� ������ �Ÿ� �����ִ� �Լ�
double Collision::Distance(const CVector2& p1, const CVector2& p2) {
	double distance;

	//��Ÿ����� ����
	//pow(x,2) --> x�� 2��, sqrt() ������
	distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

	return distance;
};


//�浹ó�� �Լ�
void Collision::ComputeCollision(CPlayer &player, CBall &ball) {

	std::cout << "�浹 ó���Լ� ����" << std::endl;

	CVector2 Dir;
	CVplayerDir = player.GetDirection();	//A
	CVballDir = ball.GetDirection();		//B

	// ���⺤�� ->AB = B - A 
	Dir = CVballDir - CVplayerDir;

	// �ε��� Ball �� ������ ���⺤�ͷ� ��ȯ�ϱ�.
	ball.SetDirection(Dir);
};
