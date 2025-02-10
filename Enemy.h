#pragma once

class Enemy 
{
public:
   Enemy();
   void Update();
   void Draw();
   int GetPosX() { return posX_; };
   int GetPosY() { return posY_; };
   int GetRadius() { return radius_; };
   int GetSpeed() { return speed_; };
   void SetPosition(int x, int y, int radius, int speed);
   int alive_;
   int time_;
   int HP_;

private:
   int posX_;
   int posY_;
   int radius_;
   int speed_;
   
  
};

