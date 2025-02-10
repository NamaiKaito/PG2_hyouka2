#include <Novice.h>
#include"Player.h"
#include"Enemy.h"
#include<math.h>
const char kWindowTitle[] = "GC1A_10_ナマイ_カイト_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	Player* player = new Player();
	Enemy* enemy = new Enemy();
	player->SetPosition(640, 620, 25, 8);
	enemy->SetPosition(640, 250, 50, 10);
	enum Scene {
		SCENE1,
		SCENE2
	};
	int scene = SCENE1;
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		switch (scene) {
		case SCENE1:
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				scene = SCENE2;
			}
			enemy->HP_ = 3;
			break;
		case SCENE2:
			player->Update(keys);
			enemy->Update();
			if (player->alive_) {
				if (player->GetRadius() + enemy->GetRadius() >= sqrtf((float)pow(player->GetPosX() - enemy->GetPosX(), 2) + (float)pow(player->GetPosY() - enemy->GetPosY(), 2))) {
					player->alive_ = false;
				}
			}
			if (enemy->alive_) {
				if (player->bulletShot_) {
					if (enemy->GetRadius() + player->radiusBullet_ >= sqrtf((float)pow(enemy->GetPosX() - player->posBulletX_, 2) + (float)pow(enemy->GetPosY() - player->posBulletY_, 2))) {
						enemy->alive_ = false;
						player->bulletShot_ = false;
						enemy->HP_ -= 1;
					}
				}
			}
			if (enemy->HP_ <= 0) {
				scene = SCENE1;
			}
			break;
		}
		///
		/// ↑更新処理ここまで
		///
		switch (scene) {
		case SCENE1:
			Novice::ScreenPrintf(640, 360, "SPACE");
			break;
		case SCENE2:
			player->Draw();
		    enemy->Draw();
			break;
		}
		
		///
		/// ↓描画処理ここから
		///
		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();
		
		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete player;
	delete enemy;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
