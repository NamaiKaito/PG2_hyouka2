#include "Player.h"
#include "Novice.h"
Player::Player(){
	posX_ = 640;
	posY_ = 620;
	speed_ = 8;
	radius_ = 25;
	alive_ = true;
	time_ = 0;
	shootCoolTime_ = 0;

	posBulletX_ = -128;
	posBulletY_ = -128;
	radiusBullet_ = 10;
	speedBullet_ = 10;
	bulletShot_ = false;
}
void Player::SetPosition(int x, int y, int radius,
	int speed) {
	posX_ = x;
	posY_ = y;
	radius_ = radius;
	speed_ = speed;
}
void Player::Update(char*keys) {
	if (alive_) {
		if (keys[DIK_W]) {
			posY_ -= speed_;
			if (posY_ - radius_ <= 0) {
				posY_ += speed_;
			}
		}
		if (keys[DIK_A]) {
			posX_ -= speed_;
			if (posX_ - radius_ <= 0) {
				posX_ += speed_;
			}
		}
		if (keys[DIK_S]) {
			posY_ += speed_;
			if (posX_ + radius_ >= 1280) {
				posX_ -= speed_;
			}
		}
		if (keys[DIK_D]) {
			posX_ += speed_;
			if (posY_ + radius_ >= 720) {
				posY_ -= speed_;
			}
		}

		if (keys[DIK_SPACE]) {
			if (shootCoolTime_ > 0) {
				shootCoolTime_--;
			} else {
				shootCoolTime_ = 10;
			}
			if (shootCoolTime_ <= 0) {
				if (!bulletShot_) {
					bulletShot_ = true;
					posBulletX_ = posX_;
					posBulletY_ = posY_;
				}
			}
		}
		if (bulletShot_) {
			posBulletY_ -= speedBullet_;
			if (posBulletY_ <= 0 - radiusBullet_) {
				bulletShot_ = false;
			}
		}
	} else {
		if (time_ > 120) {
			time_--;
		} else {
			time_ = 120;
			alive_ = true;
		}
	}
}
void Player::Draw() {
	if (alive_) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
	if (bulletShot_) {
		Novice::DrawEllipse(posBulletX_, posBulletY_, radiusBullet_, radiusBullet_, 0.0f, WHITE, kFillModeSolid);
	}
}