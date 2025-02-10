#include "Enemy.h"
#include"Player.h"
#include "Novice.h"
Enemy::Enemy()
{
	posX_ = 640;
	posY_ = 250;
	radius_ = 50;
	speed_ = 10;
	alive_ = true;
	time_ = 120;
	HP_ = 3;
}
void Enemy::SetPosition(int x, int y, int radius, int speed) {
	posX_ = x;
	posY_ = y;
	radius_ = radius;
	speed_ = speed;
}
void Enemy::Update() {
		posX_ += speed_;
		if (posX_ >= 1280 - radius_ || posX_ <= 0 + radius_) {
			speed_ *= -1;
		} else {
			if (time_ > 120) {
				time_--;
			} else {
				time_ = 120;
				alive_ = true;
			}
		}
}

void Enemy::Draw() {
	if (alive_) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
	} else {
		if (time_ >= 90) {
			if (time_ % 2 == 0) {
				
			}
		}
	}
}
