#pragma once
class Player
{
public:
	Player();
	void Update(char*keys);
	void Draw();
	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetRadius() { return radius_; };
	int GetSpeed() { return speed_; };
	void SetPosition(int x, int y, int radius,
		int speed);
	
	int posBulletX_;
	int posBulletY_;
	int radiusBullet_;
	int speedBullet_;
	int bulletShot_;
	int time_;
	int alive_;
	int shootCoolTime_;

private:
	int posX_;
	int posY_;
	int radius_;
	int speed_;
	

	
};

