#include "Debug\Header.h"
#define TWidth 10//テーブルの横幅
#define THeight 6//テーブルの縦幅
#define PIECECOUNT 12 //総ピース数
#define MINOCOUNT 5 //一つのピースを構成している正方形の数
#define MUSIC 7 //初期設定では4曲だが可能な範囲で7曲予定
class Pentomino {

public:

	Pentomino::Pentomino() {
		pent[1].name = "F";
		pent[2].name = "I";
		pent[3].name = "L";
		pent[4].name = "N";
		pent[5].name = "P";
		pent[6].name = "T";
		pent[7].name = "U";
		pent[8].name = "V";
		pent[9].name = "W";
		pent[10].name = "X";
		pent[11].name = "Y";
		pent[12].name = "Z";
		char buf[50] = "./Data/Pentomino.";
		char buff[50];
		int handle, wid, hei, r, g, b, a, cr, cb, cg;
		for (int p = 1; p < PIECECOUNT + 1; p++) {//初期化ループ
			strcpy_s(buff, 50, buf);
			strcat_s(buff, 50, pent[p].name);
			strcat_s(buff, 50, ".png");
			pent[p].image = LoadGraph(buff);
			handle = LoadARGB8ColorSoftImage(buff);
			GetGraphSize(pent[p].image, &pent[p].width, &pent[p].height);
			GetSoftImageSize(handle, &wid, &hei);
			switch (p) {
			case 1:
				cr = 255;
				cg = 0;
				cb = 0;
				break;
			case 2:
				cr = 255;
				cg = 100;
				cb = 0;
				break;
			case 3:
				cr = 200;
				cg = 200;
				cb = 0;
				break;
			case 4:
				cg = 255;
				cr = 100;
				cb = 0;
				break;
			case 5:
				cg = 255;
				cr = 0;
				cb = 0;
				break;
			case 6:
				cg = 255;
				cr = 0;
				cb = 100;
				break;
			case 7:
				cb = 200;
				cg = 200;
				cr = 0;
				break;
			case 8:
				cb = 255;
				cr = 0;
				cg = 100;
				break;
			case 9:
				cb = 255;
				cg = 0;
				cr = 0;
				break;
			case 10:
				cb = 255;
				cg = 0;
				cr = 100;
				break;
			case 11:
				cr = 200;
				cg = 0;
				cb = 200;
				break;
			case 12:
				cr = 255;
				cg = 0;
				cb = 100;
				break;
			}
			for (int x = 0; x < wid; x++) {
				for (int y = 0; y < hei; y++) {
					GetPixelSoftImage(handle, x, y, &r, &g, &b, &a);
					if (a != 0) {
						DrawPixelSoftImage(handle, x, y, cr, cg, cb, 255);
					}
					else {
						DrawPixelSoftImage(handle, x, y, 0, 0, 0, 0);
					}
				}
			}
			shadow[p] = CreateGraphFromSoftImage(handle);
			switch (p) {//原型時を基準とした中心点から見た他部分の直交距離を初期化
			case 1://F
				pent[p].fan[0].x = -1;
				pent[p].fan[0].y = 0;
				pent[p].fan[1].x = 0;
				pent[p].fan[1].y = 1;
				pent[p].fan[2].x = 0;
				pent[p].fan[2].y = -1;
				pent[p].fan[3].x = 1;
				pent[p].fan[3].y = -1;
				pent[p].fan[4].x = 40;
				pent[p].fan[4].y = 40;
				break;
			case 2://I
				pent[p].fan[0].x = 0;
				pent[p].fan[0].y = -1;
				pent[p].fan[1].x = 0;
				pent[p].fan[1].y = -2;
				pent[p].fan[2].x = 0;
				pent[p].fan[2].y = 1;
				pent[p].fan[3].x = 0;
				pent[p].fan[3].y = 2;
				pent[p].fan[4].x = 0;
				pent[p].fan[4].y = 80;
				break;
			case 3://L
				pent[p].fan[0].x = 0;
				pent[p].fan[0].y = -2;
				pent[p].fan[1].x = 0;
				pent[p].fan[1].y = -1;
				pent[p].fan[2].x = 0;
				pent[p].fan[2].y = 1;
				pent[p].fan[3].x = 1;
				pent[p].fan[3].y = 1;
				pent[p].fan[4].x = 0;
				pent[p].fan[4].y = 80;
				break;
			case 4://N
				pent[p].fan[0].x = -1;
				pent[p].fan[0].y = -1;
				pent[p].fan[1].x = -1;
				pent[p].fan[1].y = 0;
				pent[p].fan[2].x = 0;
				pent[p].fan[2].y = 1;
				pent[p].fan[3].x = 0;
				pent[p].fan[3].y = 2;
				pent[p].fan[4].x = 40;
				pent[p].fan[4].y = 40;
				break;
			case 5://P
				pent[p].fan[0].x = 0;
				pent[p].fan[0].y = -1;
				pent[p].fan[1].x = 1;
				pent[p].fan[1].y = -1;
				pent[p].fan[2].x = 1;
				pent[p].fan[2].y = 0;
				pent[p].fan[3].x = 0;
				pent[p].fan[3].y = 1;
				pent[p].fan[4].x = 0;
				pent[p].fan[4].y = 40;
				break;
			case 6://T
				pent[p].fan[0].x = -1;
				pent[p].fan[0].y = -1;
				pent[p].fan[1].x = 0;
				pent[p].fan[1].y = -1;
				pent[p].fan[2].x = 1;
				pent[p].fan[2].y = -1;
				pent[p].fan[3].x = 0;
				pent[p].fan[3].y = 1;
				pent[p].fan[4].x = 40;
				pent[p].fan[4].y = 40;
				break;
			case 7://U
				pent[p].fan[0].x = -1;
				pent[p].fan[0].y = -1;
				pent[p].fan[1].x = -1;
				pent[p].fan[1].y = 0;
				pent[p].fan[2].x = 1;
				pent[p].fan[2].y = 0;
				pent[p].fan[3].x = 1;
				pent[p].fan[3].y = -1;
				pent[p].fan[4].x = 40;
				pent[p].fan[4].y = 40;
				break;
			case 8://V
				pent[p].fan[0].x = 0;
				pent[p].fan[0].y = -1;
				pent[p].fan[1].x = 0;
				pent[p].fan[1].y = -2;
				pent[p].fan[2].x = 1;
				pent[p].fan[2].y = 0;
				pent[p].fan[3].x = 2;
				pent[p].fan[3].y = 0;
				pent[p].fan[4].x = 0;
				pent[p].fan[4].y = 80;
				break;
			case 9://W
				pent[p].fan[0].x = -1;
				pent[p].fan[0].y = -1;
				pent[p].fan[1].x = 0;
				pent[p].fan[1].y = -1;
				pent[p].fan[2].x = 1;
				pent[p].fan[2].y = 0;
				pent[p].fan[3].x = 1;
				pent[p].fan[3].y = 1;
				pent[p].fan[4].x = 40;
				pent[p].fan[4].y = 40;
				break;
			case 10://X
				pent[p].fan[0].x = -1;
				pent[p].fan[0].y = 0;
				pent[p].fan[1].x = 0;
				pent[p].fan[1].y = -1;
				pent[p].fan[2].x = 1;
				pent[p].fan[2].y = 0;
				pent[p].fan[3].x = 0;
				pent[p].fan[3].y = 1;
				pent[p].fan[4].x = 40;
				pent[p].fan[4].y = 40;
				break;
			case 11://Y
				pent[p].fan[0].x = -1;
				pent[p].fan[0].y = 0;
				pent[p].fan[1].x = 0;
				pent[p].fan[1].y = -1;
				pent[p].fan[2].x = 0;
				pent[p].fan[2].y = 1;
				pent[p].fan[3].x = 0;
				pent[p].fan[3].y = 2;
				pent[p].fan[4].x = 40;
				pent[p].fan[4].y = 40;
				break;
			case 12://Z
				pent[p].fan[0].x = 0;
				pent[p].fan[0].y = -1;
				pent[p].fan[1].x = 1;
				pent[p].fan[1].y = -1;
				pent[p].fan[2].x = 0;
				pent[p].fan[2].y = 1;
				pent[p].fan[3].x = -1;
				pent[p].fan[3].y = 1;
				pent[p].fan[4].x = 40;
				pent[p].fan[4].y = 40;
				break;
			}
			Player.p[p] = pent[p];
			pent[p].angle = 0;
		}
		DeleteSoftImage(handle);
		Forbidden.revolution = false;
		Forbidden.upset = false;
		display = MakeGraph(220, 140);
		agecorner = LoadGraph("./Data/board.agecorner.png");
		cell = LoadGraph("./Data/board.cell.png");
		nearcell = LoadGraph("./Data/board.nearcell.png");
		evilcell = LoadGraph("./Data/board.evilcell.png");
		mino = LoadGraph("./Data/Mino.png");
		nextp = LoadGraph("./Data/Next.png");
		neil = LoadGraph("./Data/Neil.png");
		PieceRow = LoadGraph("./Data/PieceRow.png");
		Turn = LoadGraph("./Data/Turn.png");
		button = LoadGraph("./Data/button.png");
		UDreverse = LoadGraph("./Data/UDReverse.png");
		LRreverse = LoadGraph("./Data/LRReverse.png");
	}

	//10×6の盤面を初期化する。
	void ClearTable() {
		for (int x = 1; x < TWidth + 1; x++) {
			for (int y = 1; y < THeight + 1; y++) {
				Table[x][y].board = 0;
				Table[x][y].check = -1;
			}
			pent[x].angle = 0;
		}
		pcount = 0;
	}

	//ピースの順番をランダムで決める。PresetやNotUseで指定されているピースは対象としない。
	void SetPlayerHand() {
		int setrand[PIECECOUNT + 1];
		int rank[PIECECOUNT + 1];
		for (int p = 1; p < PIECECOUNT + 1; p++) {			
			setrand[p] = GetRand(100);
			rank[p] = p;
		}
		int temp;
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			for (int pp = 1; pp < 13; pp++) {
				if (setrand[p] <= setrand[pp]) {
					temp = rank[p];
					rank[p] = rank[pp];
					rank[pp] = temp;
				}
			}
		}
		int r;
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			r = rank[p];
			if (r == 1) {
				Player.root = p;
				Player.pp[p] = 0;
			}
			if (r == 12) {
				Player.np[p] = 13;
			}
			for (int rp = 1; rp < 13; rp++) {
				if (rank[rp] == r - 1) {
					Player.np[rp] = p;
				}
				if (rank[rp] == r + 1) {
					Player.pp[rp] = p;
				}
			}
		}
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			if (Player.play[p] == -1) {
				if (Player.root == p) {
					Player.root = Player.np[p];
				}
				Player.pp[Player.np[p]] = Player.pp[p];
				Player.np[Player.pp[p]] = Player.np[p];
			}
		}
	}
	//ニューゲームを始めるための準備。
	void NewGame() {
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			Player.play[p] = 0;
			Player.set[p].x = 0;
			Player.set[p].y = 0;
			
			Player.shadow[p] = shadow[p];
			Player.played = 0;
			//回転・反転された画像とデータを初期状態に戻す。
			Player.p[p] = pent[p];			
		}
		Player.choose = 0;
		Forbidden.all = false;
		Forbidden.revolution = false;
		Forbidden.upset = false;
		Forbidden.rest = 0;	
		Forbidden.initturn = 0;
		ClearTable();
		buttonwait = 30;
		hintcount = 0;
	}
	
	//NewGame後にPENTAクラスのStagedataからHintの情報を受け取り、ヒント画像を作成します。
	void GetHint(int h,int p, int x, int y, int a) {
		hint[h].x = (x - 1) * 20 + 30;
		hint[h].y = (y - 1) * 20 + 30;
		int soft = MakeARGB8ColorSoftImage(200, 200);
		int r, g, b;
		Getminostyle(p,r,g,b);
		int hx, hy;
		int x1, y1, x2, y2;//GetDrawScreenGraphにてトリミングする画像の左上＆右下座標
		x1 = 100;
		y1 = 100;
		x2 = 100;
		y2 = 100;
		SetDrawScreen(soft);
		for (int ix = 0; ix < 201; ix++) {
			for (int iy = 0; iy < 201; iy++) {
				DrawPixelSoftImage(soft, ix, iy, r, g, b, 0);
			}
		}
		for (int ix = 100; ix < 121; ix++) {
			for (int iy = 100; iy < 121; iy++) {
				DrawPixelSoftImage(soft, ix, iy, r, g, b, 255);
			}
		}
		for (int f = 0; f < MINOCOUNT - 1; f++) {
			hx = Player.p[p].fan[f].x * 20;
			hy = Player.p[p].fan[f].y * 20;
			SetPieceAngle(a, hx, hy);
			hx += 100;
			hy += 100;
			for (int ix = hx; ix < hx + 21; ix++) {
				for (int iy = hy; iy < hy + 21; iy++) {
					DrawPixelSoftImage(soft, ix, iy, r, g, b, 255);
				}
			}
			if (hx < x1) {
				x1 = hx;
			}
			if (hy < y1) {
				y1 = hy;
			}
			if (hx > x2) {
				x2 = hx;
			}
			if (hy > y2) {
				y2 = hy;
			}
		}
		hint[h].image = DerivationGraph(x1, y1, x2 - x1 + 20, y2 - y1 + 20, CreateGraphFromSoftImage(soft));
		DeleteSoftImage(soft);
		hint[h].x -= (100 - x1);
		hint[h].y -= (100 - y1);
		SetDrawScreen(DX_SCREEN_BACK);	
		/*//ヒント画像の確認用
		DrawBox(1, 1, 640, 480, GetColor(0, 0, 0), true);
		DrawGraph(50, 50, hint[h].image, true);
		char buf[244];
		_itoa_s((hint[h].x - 30) / 20, buf,244, 10);		
		DrawString(150, 100, buf, GetColor(255, 255, 255));
		_itoa_s((hint[h].y - 30) / 20, buf, 244, 10);
		DrawString(150, 150, buf, GetColor(255, 255, 255));
		ScreenFlip();
		WaitKey();
		//*/
	}

	//盤面にピースを敷き詰めた事による余剰ピース数を登録します。ソート用
	void SetRestPiece(int rest) {
		Forbidden.rest += rest;
	}

	//盤面上のクリックされたカーソル位置を元に盤面情報をサーチします。設置済みかつ移動可能なピースがある場合はそのピースを再度選択状態にします。
	void SearchBoard(int x, int y) {
		int sx = (int)((x - 40) / 40) + 1;
		int sy = (int)((y - 40) / 40) + 1;
		if (Table[sx][sy].board > 0) {
			int p = (Table[sx][sy].board > 100) ? Table[sx][sy].board - 100 : Table[sx][sy].board;
			if (Player.play[p] != -1) {
				Player.choose = p;
				Player.mcx = x - Player.set[p].x;
				Player.mcy = y - Player.set[p].y;
				Player.cx = Player.set[p].x;
				Player.cy = Player.set[p].y;
				sx = (Player.set[p].x + Player.p[p].fan[4].x) / 40;
				sy = (Player.set[p].y + Player.p[p].fan[4].y) / 40;
				Player.set[p].x = 0;
				Player.set[p].y = 0;
				for (int pl = 1; pl < PIECECOUNT + 1; pl++) {
					if (Player.play[p] < Player.play[pl]) {
						Player.play[pl]--;
					}
				}
				Player.play[p] = 0;
				Player.played--;
				for (int f = 0; f < 5; f++) {
					if (f == 4) {
						Table[sx][sy].board = 0;
					}
					else {
						Table[sx + Player.p[p].fan[f].x][sy + Player.p[p].fan[f].y].board = 0;
					}
				}
				if (Player.cy < 80) {
					if (Forbidden.revolution == false) {
						Button.rx = Player.cx + Player.p[Player.choose].width / 2 - 73;
						Button.ry = Player.cy + Player.p[Player.choose].height + 5;
					}
					else {
						Button.rx = 0;
						Button.ry = 0;
					}
					if (Forbidden.upset == false) {
						Button.vx = Player.cx + +Player.p[Player.choose].width / 2 - 23;
						Button.vy = Player.cy + Player.p[Player.choose].height + 5;
						Button.hx = Player.cx + +Player.p[Player.choose].width / 2 + 27;
						Button.hy = Player.cy + Player.p[Player.choose].height + 5;
					}
					else {
						Button.vx = 0;
						Button.vy = 0;
						Button.hx = 0;
						Button.hy = 0;
					}

				}
				else {
					if (Forbidden.revolution == false) {
						Button.rx = Player.cx + Player.p[Player.choose].width / 2 - 73;
						Button.ry = Player.cy - 60;
					}
					else {
						Button.rx = 0;
						Button.ry = 0;
					}
					if (Forbidden.upset == false) {
						Button.vx = Player.cx + Player.p[Player.choose].width / 2 - 23;
						Button.vy = Player.cy - 60;
						Button.hx = Player.cx + Player.p[Player.choose].width / 2 + 27;
						Button.hy = Player.cy - 60;
					}
					else {
						Button.vx = 0;
						Button.vy = 0;
						Button.hx = 0;
						Button.hy = 0;
					}
				}
			}
		}
	}

	//プレイヤー操作によって1.90度回転 2.上下反転 3.左右反転ボタンが押されたため選択状態にあるピースに適用する。
	int PlayerOperate(int button, int p) {
		if (buttonwait == 0) {
			int temp;
			int newgraph, newshadow;
			int vx, vy;
			buttonwait = 30;
			switch (button) {
			case 1://90度回転
				switch (Player.p[p].angle) {
				case 0:
				case 1:
				case 2:
				case 4:
				case 5:
				case 6:
					Player.p[p].angle++;
					break;
				case 3:
					Player.p[p].angle = 0;
					break;
				case 7:
					Player.p[p].angle = 4;
					break;
				}
				if (Player.p[p].angle == 0) {
					Player.p[p].image = pent[p].image;
					Player.shadow[p] = shadow[p];
				}
				else {
					newgraph = MakeScreen(Player.p[p].height, Player.p[p].width, TRUE);
					//newgraph = MakeScreen(200, 200, TRUE);
					SetDrawScreen(newgraph);
					SetCreateDrawValidGraphMultiSample(4, 8);
					temp = DrawRotaGraph(Player.p[p].height / 2, Player.p[p].width / 2, 1.0, 90 * PI / 180, Player.p[p].image, TRUE);
					Player.p[p].image = newgraph;
					newshadow = MakeScreen(Player.p[p].height, Player.p[p].width, TRUE);
					SetDrawScreen(newshadow);
					DrawRotaGraph(Player.p[p].height / 2, Player.p[p].width / 2, 1.0, 90 * PI / 180, Player.shadow[p], TRUE);
					Player.shadow[p] = newshadow;
				}
				SetDrawScreen(DX_SCREEN_BACK);
				vx = Player.p[p].fan[4].x * -1;
				vy = Player.p[p].height - Player.p[p].fan[4].y - 40;
				Player.p[p].fan[4].x = vy;
				Player.p[p].fan[4].y = vx * -1;
				for (int f = 0; f < 4; f++) {
					vx = Player.p[p].fan[f].y * -1;
					vy = Player.p[p].fan[f].x;
					Player.p[p].fan[f].x = vx;
					Player.p[p].fan[f].y = vy;
				}
				GetGraphSize(Player.p[p].image, &Player.p[p].width, &Player.p[p].height);
				if (Player.cy < 81 || Player.cy < Button.ry || Player.cy < Button.vy) {
					if (Forbidden.revolution == false) {
						Player.cy = Button.ry - 3 - Player.p[Player.choose].height;
					}
					else {
						Player.cy = Button.vy - 3 - Player.p[Player.choose].height;
					}
				}
				if (Player.cy < 10) {
					int absy = Button.ry - Player.cy;
					Player.cy = 10;
					Button.ry = 10 + absy;
					Button.hy = 10 + absy;
					Button.vy = 10 + absy;
				}
				if (Forbidden.revolution == false) {
					Player.cx = Button.rx + 75 - Player.p[Player.choose].width / 2;
				}
				else {
					Player.cx = Button.vx + 25 - Player.p[Player.choose].width / 2;
				}

				break;
			case 2://上下反転
				if (Player.p[p].angle > 3) {
					Player.p[p].angle = Player.p[p].angle - 4;
				}
				else {
					Player.p[p].angle = Player.p[p].angle + 4;
				}
				if (Player.p[p].angle == 0) {
					Player.p[p].image = pent[p].image;
					Player.shadow[p] = shadow[p];
				}
				else {
					newgraph = MakeScreen(Player.p[p].width, Player.p[p].height, TRUE);
					//newgraph = MakeScreen(200, 200, TRUE);
					SetDrawScreen(newgraph);
					SetCreateDrawValidGraphMultiSample(4, 8);
					temp = DrawReverseGraph(0, 0, Player.p[p].image, TRUE, FALSE, TRUE);
					Player.p[p].image = newgraph;
					newshadow = MakeScreen(Player.p[p].width, Player.p[p].height, TRUE);
					SetDrawScreen(newshadow);
					temp = DrawReverseGraph(0, 0, Player.shadow[p], TRUE, FALSE, TRUE);
					Player.shadow[p] = newshadow;
				}
				SetDrawScreen(DX_SCREEN_BACK);
				vx = Player.p[p].fan[4].x;
				vy = Player.p[p].height - Player.p[p].fan[4].y - 40;
				Player.p[p].fan[4].x = vx;
				Player.p[p].fan[4].y = vy;
				for (int f = 0; f < 4; f++) {
					vx = Player.p[p].fan[f].x;
					vy = Player.p[p].fan[f].y * -1;
					Player.p[p].fan[f].x = vx;
					Player.p[p].fan[f].y = vy;
				}
				break;
			case 3://左右反転
				if (Player.p[p].angle < 4) {
					Player.p[p].angle = (Player.p[p].angle + 2) % 4 + 4;
				}
				else {
					Player.p[p].angle = (Player.p[p].angle - 2) % 4;
				}
				if (Player.p[p].angle == 0) {
					Player.p[p].image = pent[p].image;
					Player.shadow[p] = shadow[p];
				}
				else {
					newgraph = MakeScreen(Player.p[p].width, Player.p[p].height, TRUE);
					//newgraph = MakeScreen(200, 200, TRUE);
					SetDrawScreen(newgraph);
					SetCreateDrawValidGraphMultiSample(4, 8);
					temp = DrawReverseGraph(0, 0, Player.p[p].image, TRUE, TRUE, FALSE);
					Player.p[p].image = newgraph;
					newshadow = MakeScreen(Player.p[p].width, Player.p[p].height, TRUE);
					SetDrawScreen(newshadow);
					temp = DrawReverseGraph(0, 0, Player.shadow[p], TRUE, TRUE, FALSE);
					Player.shadow[p] = newshadow;
				}
				SetDrawScreen(DX_SCREEN_BACK);
				vx = Player.p[p].width - Player.p[p].fan[4].x - 40;
				vy = Player.p[p].fan[4].y;
				Player.p[p].fan[4].x = vx;
				Player.p[p].fan[4].y = vy;
				for (int f = 0; f < 4; f++) {
					vx = Player.p[p].fan[f].x * -1;
					vy = Player.p[p].fan[f].y;
					Player.p[p].fan[f].x = vx;
					Player.p[p].fan[f].y = vy;
				}
				break;
			}
			return 0;
		}else {
			return -1;
		}
	}

	//盤面にドラッグされたピースが盤面に設置可能かどうかを調べます。設置可能な場合はPlayer.ablex,ableyに座標が登録されます。
	void AbleSet() {

		int ax = (int)((Player.cx + Player.p[Player.choose].fan[4].x - 40) / 40) + 1;
		int ay = (int)((Player.cy + Player.p[Player.choose].fan[4].y - 40) / 40) + 1;
		bool able = true;
		for (int f = 0; f < 5; f++) {
			//4(中心点),0,1,2,3という順番でチェックする。
			if (f == 0) {
				if (Table[ax][ay].board != 0) {
					able = false;
					break;
				}
			}
			else {
				int c = Player.choose;
				if (Table[ax + Player.p[c].fan[f - 1].x][ay + Player.p[c].fan[f - 1].y].board != 0) {
					able = false;
					break;
				}
			}
		}
		Player.ablex = (int)((Player.cx + 20) / 40) * 40;
		Player.abley = (int)((Player.cy + 20) / 40) * 40;
		ax = (Player.ablex + Player.p[Player.choose].fan[4].x) / 40;
		ay = (Player.abley + Player.p[Player.choose].fan[4].y) / 40;
		for (int f = 0; f < 5; f++) {
			//4(中心点),0,1,2,3という順番でチェックする。
			if (f == 0) {
				if (Table[ax][ay].board != 0) {
					able = false;
					break;
				}
			}
			else {
				int c = Player.choose;
				if (Table[ax + Player.p[c].fan[f - 1].x][ay + Player.p[c].fan[f - 1].y].board != 0) {
					able = false;
					break;
				}
			}
		}
		if (able) {
			Player.ablex = (int)((Player.cx + 20) / 40) * 40;
			Player.abley = (int)((Player.cy + 20) / 40) * 40;
		}
		else {
			Player.ablex = 0;
			Player.abley = 0;
		}
	}

	//プレイヤー操作によるピース設置情報を登録する。
	void PlayerSet(int p) {
		int ax = (int)((Player.cx + Player.p[p].fan[4].x - 20) / 40) + 1;
		int ay = (int)((Player.cy + Player.p[p].fan[4].y - 20) / 40) + 1;
		for (int f = 0; f < 5; f++) {
			//4(中心点),0,1,2,3という順番でチェックする。
			if (f == 0) {
				Table[ax][ay].board = p + 100;
			}
			else {
				Table[ax + Player.p[p].fan[f - 1].x][ay + Player.p[p].fan[f - 1].y].board = p;
			}
		}
		Player.ablex = 0;
		Player.abley = 0;
	}

	//プレイヤーが1手戻るボタンを押したことで手番の1つ前まで戻ります。
	void PlayerUndo() {
		if (Player.played > 0 && buttonwait == 0) {
			int p = 1;
			while (p < PIECECOUNT + 1 && Player.play[p] != Player.played) {
				p++;
			}
			if (p < PIECECOUNT + 1) {
				Player.pp[Player.root] = p;
				Player.np[p] = Player.root;
				Player.pp[p] = 0;
				Player.root = p;
				Player.played--;
				int sx = (Player.set[p].x + Player.p[p].fan[4].x) / 40;
				int sy = (Player.set[p].y + Player.p[p].fan[4].y) / 40;
				for (int f = 0; f < 5; f++) {
					if (f == 4) {
						Table[sx][sy].board = 0;
					}
					else {
						Table[sx + Player.p[p].fan[f].x][sy + Player.p[p].fan[f].y].board = 0;
					}
				}
				Player.set[p].x = 0;
				Player.set[p].y = 0;
				Player.play[p] = 0;
				buttonwait = 30;
			}
		}
	}

	//プレイヤーが最初からボタンを押したことで最初からゲームをやり直します。※
	void PlayerReset() {

	}

	//プレイヤーがヒントボタンを押したことでカウントに応じたヒントを表示します。
	void PlayerHint() {
		if (hintcount < 5 && buttonwait == 0) {
			hintcount++;
			buttonwait = 30;
		}
	}

	//プレイヤーがピースをダブルクリックしたことで選択されたピースまたは盤面に設置されたピースを待ちピースに戻します。
	int PlayerRemove(int p) {
		if(buttonwait == 0){
			if (Player.choose == 0) {
				p = Player.root;
				Player.pp[Player.np[p]] = 0;
				Player.root = Player.np[p];
			}
			Player.choose = 0;
			Player.cx = 0;
			Player.cy = 0;
			Player.mcx = 0;
			Player.mcy = 0;
			int loopcount = 0;//無限ループ多発地域
			for (int tail = Player.root; tail < PIECECOUNT + 1;) {
				if (Player.np[tail] == 13) {
					Player.pp[p] = tail;
					Player.np[p] = 13;
					Player.np[tail] = p;
					break;
				}
				loopcount++;
				if (loopcount > PIECECOUNT * 2) {
					return -1;
				}
				tail = Player.np[tail];
			}
			Player.set[p].x = 0;
			Player.set[p].y = 0;
			Player.play[p] = 0;			
			Player.p[p].angle = 0;
			for (int f = 0; f < 5; f++) {
				Player.p[p].fan[f].x = pent[p].fan[f].x;
				Player.p[p].fan[f].y = pent[p].fan[f].y;
			}
			Player.p[p].image = pent[p].image;
			Player.shadow[p] = shadow[p];
			GetGraphSize(Player.p[p].image, &Player.p[p].width, &Player.p[p].height);
			if (Forbidden.revolution) {
				InitTurn(p);
			}
			buttonwait = 30;
		}
		return 0;
	}	

	//10×6の盤面状況とはめ込まれたピースを表示する。
	int DisplayBoard() {
		for (int x = 20; x < 240; x += 10) {
			DrawGraph(x, 20, agecorner, false);
			DrawGraph(x, 150, agecorner, false);
		}
		for (int y = 30; y < 150; y += 10) {
			DrawGraph(20, y, agecorner, false);
			DrawGraph(230, y, agecorner, false);
		}
		
		int img;
		for (int x = 30; x < 230; x += 20) {
			for (int y = 30; y < 150; y += 20) {
				if (Table[(int)((x - 10) / 20)][(int)((y - 10) / 20)].board == -1) {
					img = evilcell;
				}else{
					if (Table[(int)((x - 10) / 20)][(int)((y - 10) / 20)].check == -1) {
						img = cell;
					}
					else {
						img = nearcell;
					}
					
				}
				DrawGraph(x, y, img, false);
			}
		}
		for (int h = 1; h < hintcount + 1; h++) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
			DrawGraph(hint[h].x, hint[h].y, hint[h].image, true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
		}
		int color;
		for (int x = 30; x < 230; x += 20) {
			for (int y = 30; y < 150; y += 20) {
				if (Table[(int)((x - 10) / 20)][(int)((y - 10) / 20)].board > 0) {
					DrawGraph(x, y, Player.style, false);
				}
				color = Table[(int)((x - 10) / 20)][(int)((y - 10) / 20)].board;
				if (color > 100) {
					color -= 100;
					if (Player.play[color] == -1) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
						DrawBox(x, y, x + 20, y + 20, GetColor(0, 0, 0), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
						DrawGraph(x, y, neil, true);
					}
				}
				else {
					if (Player.play[color] == -1) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
						DrawBox(x, y, x + 20, y + 20, GetColor(0, 0, 0), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
					}
				}
			}
		}
		int r = GetDrawScreenGraph(20, 20, 240, 160, display);
		DrawExtendGraph(20, 20, 460, 300, display, false);		
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			//盤面に設置されたピースを表示
			if (Player.set[p].x != 0) {
				if (Player.style == mino) {
					DrawGraph(Player.set[p].x, Player.set[p].y, Player.p[p].image, TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawGraph(Player.set[p].x, Player.set[p].y, Player.shadow[p], TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
			}
			if (Player.root == 0 || Player.np[p] == 0) {
				p = p;
			}
		}
		
		for (int y = 19; y < 230; y += 70) {
			DrawGraph(489, y, button, true);
			switch ((y + 51) / 70) {
			case 1:
				DrawString(520, 37, "1手戻す", GetColor(0, 0, 0));
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawBox(491, y + 2, 609, y + 50, GetColor(200, 75, 75), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
				break;
			case 2:
				DrawString(520, y + 18, "最初から", GetColor(0, 0, 0));
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawBox(491, y + 2, 609, y + 50, GetColor(200, 200, 75), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
				break;
			case 3:
				DrawString(530, y + 18, "Porse", GetColor(0, 0, 0));
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawBox(491, y + 2, 609, y + 50, GetColor(75, 200, 75), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
				break;
			case 4:
				DrawString(530, y + 18, "ヒント", GetColor(0, 0, 0));
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawBox(491, y + 2, 609, y + 50, GetColor(75, 75, 200), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
				break;
			}
		}
		if (Player.choose == 0) {
			DrawGraph(590, 365, nextp, true);
		}
		int count = (Player.choose == 0) ? 1 : 2;
		int pcount = 1;
		int errorcount;//待ちピース列の描写ができなかったとき、残りピース数に因むものか否かを識別するための変数
		int pp;
		DrawTurnGraph(18, 318, PieceRow, true);
		for (int p = 1; p < PIECECOUNT + 1; p++) {
				pp = Player.root;
				pcount = (Player.choose == 0) ? 1 : 2;
				while (pcount != count && pp < 13) {
					pp = Player.np[pp];
					if (Player.play[pp] == -1) {
						pcount = 10;
						break;
					}
					pcount++;
				}
				if (pp < 13 && pcount < 6) {
					if (Player.choose != pp || Player.choose == 0) {//選択状態のピースは待ちピース枠に表示しない
						int width = Player.p[pp].width;
						int height = Player.p[pp].height;
						int x1, y1, x2, y2;
						int spx = 3;int spy = 3;//柄のついたピースをミノ毎に表示するための分割数
						switch (count) {
						case 1://120×120 445-565x 335-455y 505x395y
							x1 = 445;
							x2 = 565;
							y1 = 335;
							y2 = 455;
							switch (width) {//ミノ1つあたり40×40
							case 40:
								x1 += 48;
								x2 -= 48;
								spx = 1;
								break;
							case 80:
								if (height == 160) {
									x1 += 30;
									x2 -= 30;
								}
								else {
									x1 += 20;
									x2 -= 20;
								}
								spx = 2;
								break;
							case 160:
								spx = 4;
								break;
							case 200:
								spx = 5;
								break;
							}
							switch (height) {//ミノ1つあたり40×40
							case 40:
								y1 += 48;
								y2 -= 48;
								spy = 1;
								break;
							case 80:
								spy = 2;
								if (width == 160) {
									y1 += 30;
									y2 -= 30;
								}
								else {
									y1 += 20;
									y2 -= 20;
								}
								break;
							case 160:
								spy = 4;
								break;
							case 200:
								spy = 5;
								break;
							}
							r = DrawExtendGraph(x1, y1, x2, y2, Player.p[pp].image, true);
							if (Player.style != mino) {
								int tx = x1 + Player.p[pp].fan[4].x / 40 * (x2 - x1) / spx;
								int ty = y1 + Player.p[pp].fan[4].y / 40 * (y2 - y1) / spy;
								DrawExtendGraph(tx, ty, tx + (x2 - x1) / spx, ty + (y2 - y1) / spy, Player.style, true);
								int ttx, tty;
								for (int f = 0; f < 4; f++) {
									ttx = tx + Player.p[pp].fan[f].x * (x2 - x1) / spx;
									tty = ty + Player.p[pp].fan[f].y * (y2 - y1) / spy;
									DrawExtendGraph(ttx, tty, ttx + (x2 - x1) / spx, tty + (y2 - y1) / spy, Player.style, true);
								}
							}
							if ((pcount == 1 || Player.choose == 0) && AllTableSet() == false) {
								if (Forbidden.revolution == false) {
									Button.rx = 435;
									Button.ry = 265;
									SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
									DrawBox(Button.rx, Button.ry, Button.rx + 50, Button.ry + 50, GetColor(150, 150, 50), true);
									SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
									DrawGraph(430, 265, Turn, true);
								}
								else {
									Button.rx = 0;
									Button.ry = 0;
								}
								if (Forbidden.upset == false) {
									Button.vx = 485;
									Button.vy = 265;
									Button.hx = 535;
									Button.hy = 265;
									SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
									DrawBox(Button.vx, Button.vy, Button.vx + 50, Button.vy + 50, GetColor(50, 50, 200), true);
									DrawBox(Button.hx, Button.hy, Button.hx + 50, Button.hy + 50, GetColor(50, 200, 50), true);
									SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
									DrawGraph(485, 265, UDreverse, true);
									DrawGraph(535, 265, LRreverse, true);
								}
								else {
									Button.hx = 0;
									Button.hy = 0;
									Button.vx = 0;
									Button.vy = 0;
								}
							}
							break;
						case 2:
							x1 = 370;
							x2 = 420;
							y1 = 370;
							y2 = 420;

							break;
						case 3:
							x1 = 300;
							x2 = 350;
							y1 = 370;
							y2 = 420;
							break;
						case 4:
							x1 = 230;
							x2 = x1 + 50;
							y1 = 370;
							y2 = y1 + 50;
							break;
						case 5:
							x1 = 160;
							x2 = x1 + 50;
							y1 = 370;
							y2 = y1 + 50;
							break;
						}
						if (count > 1) {
							switch (width) {//ミノ1つあたり10×10
							case 40:
								x1 += 20;
								x2 -= 20;
								spx = 1;
								break;
							case 80:
								if (height == 160) {//12.5×4
									x1 += 12;
									x2 -= 12;
								}
								else {
									x1 += 8;
									x2 -= 8;
								}
								spx = 2;
								break;
							case 160:
								spx = 4;
								break;
							case 200:
								spx = 5;
								break;
							}
							switch (height) {//ミノ1つあたり10×10
							case 40:
								y1 += 20;
								y2 -= 20;
								spy = 1;
								break;
							case 80:
								if (width == 160) {
									y1 += 12;
									y2 -= 12;
								}
								else {
									y1 += 8;
									y2 -= 8;
								}
								spy = 2;
								break;
							case 160:
								spy = 4;
								break;
							case 200:
								spy = 5;
								break;
							}							
							if (Player.style != mino) {
								int wid = (x2 - x1) / spx;
								int hei = (y2 - y1) / spy;
								int tx = x1 + Player.p[pp].fan[4].x / 40 * wid;
								int ty = y1 + Player.p[pp].fan[4].y / 40 * hei;
								r = DrawExtendGraph(tx, ty, tx + wid, ty + hei, Player.style, true);
								int ttx, tty;
								for (int f = 0; f < 4; f++) {
									if (r == -1) {
										break;
									}
									ttx = tx + Player.p[pp].fan[f].x * wid;
									tty = ty + Player.p[pp].fan[f].y * hei;
									r = DrawExtendGraph(ttx, tty, ttx + wid, tty + hei, Player.style, true);
									
								}
							}
							else {
								r = DrawExtendGraph(x1, y1, x2, y2, Player.p[pp].image, true);
							}
						}
					}
					count++;
					if (count == 6 || r == -1) {
						break;
					}
				}
				else {
					//break;
					errorcount = pcount;
					r = -1;
				}
			}
		int restp = 0;
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			if (Player.play[p] == 0) {
				restp++;
			}
		}
		DrawFormatString(25, 385, GetColor(0, 0, 0), "残り%dピース", restp);
		if (r == -1) {
			if (errorcount > restp) {//残りピース数の現象により待ちピース列に空白ができた場合は正常とする。
				r = 0;
			}
		}
		if (Player.choose > 0 && r != -1) {
			if (Player.ablex != 0) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawGraph(Player.ablex, Player.abley, Player.shadow[Player.choose], TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
				if (Player.cx + Player.p[Player.choose].width > 470 || Player.cy + Player.p[Player.choose].height > 310) {
					Player.ablex = 0;
				}
				if (Player.cx < 20 || Player.cy < 20) {
					Player.ablex = 0;
				}
			}
			DrawGraph(Player.cx, Player.cy, Player.p[Player.choose].image, true);
			if (Player.style != mino) {
				int x = Player.cx + Player.p[Player.choose].fan[4].x;
				int y = Player.cy + Player.p[Player.choose].fan[4].y;
				DrawExtendGraph(x, y, x + 40,y + 40, Player.style, true);
				int fx, fy;
				for (int f = 0; f < 4; f++) {
					fx = x + Player.p[Player.choose].fan[f].x * 40;
					fy = y + Player.p[Player.choose].fan[f].y * 40;
					DrawExtendGraph(fx, fy, fx + 40, fy + 40, Player.style, true);
				}
			}
			if (Player.click != 3) {
				int longer = (Player.p[Player.choose].width > Player.p[Player.choose].height) ? Player.p[Player.choose].width : Player.p[Player.choose].height;
				if (Player.cy < 80) {
					//各種ボタンをピースの下部に表示
					if (Forbidden.revolution == false) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
						DrawBox(Button.rx, Button.ry, Button.rx + 50, Button.ry + 50, GetColor(150, 150, 50), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
						DrawGraph(Button.rx, Button.ry, Turn, true);
					}
					else {
						Button.rx = 0;
						Button.ry = 0;
					}
					if (Forbidden.upset == false) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
						DrawBox(Button.vx, Button.vy, Button.vx + 50, Button.vy + 50, GetColor(50, 50, 200), true);
						DrawBox(Button.hx, Button.hy, Button.hx + 50, Button.hy + 50, GetColor(50, 200, 50), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
						DrawGraph(Button.vx, Button.vy, UDreverse, true);
						DrawGraph(Button.hx, Button.hy, LRreverse, true);
					}
					else {
						Button.vx = 0;
						Button.vy = 0;
						Button.hx = 0;
						Button.hy = 0;
					}

				}
				else {
					//各種ボタンをピースの上部に表示 -15 +40 +95 , -90
					if (Forbidden.revolution == false) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
						DrawBox(Button.rx, Button.ry, Button.rx + 50, Button.ry + 50, GetColor(150, 150, 50), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 150);
						DrawGraph(Button.rx, Button.ry, Turn, true);
					}
					else {
						Button.rx = 0;
						Button.ry = 0;
					}
					if (Forbidden.upset == false) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
						DrawBox(Button.vx, Button.vy, Button.vx + 50, Button.vy + 50, GetColor(50, 50, 200), true);
						DrawBox(Button.hx, Button.hy, Button.hx + 50, Button.hy + 50, GetColor(50, 200, 50), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 150);
						DrawGraph(Button.vx, Button.vy, UDreverse, true);
						DrawGraph(Button.hx, Button.hy, LRreverse, true);
					}
					else {
						Button.vx = 0;
						Button.vy = 0;
						Button.hx = 0;
						Button.hy = 0;
					}

				}
			}
			else {
				if (Player.cy < 80) {
					if (Forbidden.revolution == false) {
						Button.rx = Player.cx + Player.p[Player.choose].width / 2 - 73;
						Button.ry = Player.cy + Player.p[Player.choose].height + 5;
					}
					else {
						Button.rx = 0;
						Button.ry = 0;
					}
					if (Forbidden.upset == false) {
						Button.vx = Player.cx + +Player.p[Player.choose].width / 2 - 23;
						Button.vy = Player.cy + Player.p[Player.choose].height + 5;
						Button.hx = Player.cx + +Player.p[Player.choose].width / 2 + 27;
						Button.hy = Player.cy + Player.p[Player.choose].height + 5;
					}
					else {
						Button.vx = 0;
						Button.vy = 0;
						Button.hx = 0;
						Button.hy = 0;
					}

				}
				else {
					if (Forbidden.revolution == false) {
						Button.rx = Player.cx + Player.p[Player.choose].width / 2 - 73;
						Button.ry = Player.cy - 60;
					}
					else {
						Button.rx = 0;
						Button.ry = 0;
					}
					if (Forbidden.upset == false) {
						Button.vx = Player.cx + Player.p[Player.choose].width / 2 - 23;
						Button.vy = Player.cy - 60;
						Button.hx = Player.cx + Player.p[Player.choose].width / 2 + 27;
						Button.hy = Player.cy - 60;
					}
					else {
						Button.vx = 0;
						Button.vy = 0;
						Button.hx = 0;
						Button.hy = 0;
					}
				}

			}
		}
		
		if (buttonwait > 0) {
			buttonwait--;
		}
		//DrawFormatString(100, 100, GetColor(0, 0, 0), "cx = %d", Player.cx);
		//DrawFormatString(100, 130, GetColor(0, 0, 0), "cy = %d", Player.cy); デバッグ用
		//WaitKey();
		return r;
	}

	//ピース毎に設定された色を返します。
	int Getminostyle(int c) {
		int color = 0;
		switch (c) {
		case 1:
			color = GetColor(255, 0, 0);
			break;
		case 2:
			color = GetColor(255, 100, 0);
			break;
		case 3:
			color = GetColor(200, 200, 0);
			break;
		case 4:
			color = GetColor(100, 255, 0);
			break;
		case 5:
			color = GetColor(0, 255, 0);
			break;
		case 6:
			color = GetColor(0, 255, 100);
			break;
		case 7:
			color = GetColor(0, 200, 200);
			break;
		case 8:
			color = GetColor(0, 100, 255);
			break;
		case 9:
			color = GetColor(0, 0, 255);
			break;
		case 10:
			color = GetColor(100, 0, 255);
			break;
		case 11:
			color = GetColor(200, 0, 200);
			break;
		case 12:
			color = GetColor(255, 0, 100);
			break;
		}
		return color;
	}
	//ピース毎に設定された色をRGB別に返します。
	void Getminostyle(int c,int &r,int &g,int &b) {
		switch (c) {
		case 1:
			r = 255;
			g = 0;
			b = 0;
			break;
		case 2:
			r = 255;
			g = 100;
			b = 0;
			break;
		case 3:
			r = 200;
			g = 200;
			b = 0;
			break;
		case 4:
			r = 100;
			g = 255;
			b = 0;
			break;
		case 5:			
			r = 0;
			g = 255;
			b = 0;
			break;
		case 6:
			r = 0;
			g = 255;
			b = 100;
			break;
		case 7:
			r = 0;
			g = 200;
			b = 200;
			break;
		case 8:
			r = 0;
			g = 100;
			b = 255;			
			break;
		case 9:
			r = 0;
			g = 0;
			b = 255;			
			break;
		case 10:
			r = 100;
			g = 0;
			b = 255;			
			break;
		case 11:
			r = 200;
			g = 0;
			b = 200;
			break;
		case 12:
			r = 255;
			g = 0;
			b = 100;
			break;
		}
	}

	//それぞれのアングルに異なるピースの位置を返します。&x,&yはPlayer.p[p].fan[f].x(y)から別の変数にコピーして引用させます。
	void SetPieceAngle(int angle ,int &x,int &y) {		
		int xx = x;
		int yy = y;
		switch (angle) {
		case 0://初期状態			
			break;
		case 1://90度回転
			x = yy;
			y = xx * -1;
			break;
		case 2://180度回転
			x = xx * -1;
			y = yy * -1;
			break;
		case 3://270度回転
			x = yy * -1;
			y = xx;
			break;
		case 4://上下反転
			x = xx;
			y = yy * -1;
			break;
		case 5://上下反転&90度回転
			x = yy * -1;
			y = xx * -1;
			break;
		case 6://上下反転&180度回転
			x = xx * -1;
			y = yy;
			break;
		case 7://上下反転&270度回転
			x = yy;
			y = xx;
			break;
		}
	}
	//左右・上下反転が禁止の時、ステージ番号に応じたピースの回転を初期設定として処理します。
	void InitTurn(int p) {
		bool op = false;
		switch (Forbidden.initturn) {
		case 2://前半6つのみ回転
			if (p < PIECECOUNT / 2 + 1) {
				op = true;
			}
			break;
		case 1://後半6つのみ回転
			if (p > PIECECOUNT / 2) {
				op = true;
			}
			break;
		case 0://偶数のみ回転
			if (p % 2 == 0) {
				op = true;
			}
			break;
		case 3://奇数のみ回転
			if (p % 2 == 1) {
				op = true;
			}
			break;
		}
		if (op) {
			int wait = buttonwait;
			buttonwait = 0;
			PlayerOperate(1, p);
			buttonwait = wait;
		}
	}
	//回転禁止・反転禁止のゲーム制限を設定します。
	void SetForbidden(bool turn, bool upset,int stage) {
		Forbidden.revolution = turn;
		if (turn) {
			Forbidden.initturn = stage % 4;
			for (int p = 1; p < PIECECOUNT + 1; p++) {
				InitTurn(p);
			}
		}
		Forbidden.upset = upset;		
		Forbidden.all = (Forbidden.revolution && Forbidden.upset);
	}

	//pentaクラス外部へButtonの情報を返します。1.上下反転 2.90度回転 3.左右反転
	void GetButton(int b, int *x, int *y) {
		switch (b) {
		case 1://upset
			*x = Button.vx;
			*y = Button.vy;
			break;
		case 2://revolution
			*x = Button.rx;
			*y = Button.ry;
			break;
		case 3://mirror左右反転
			*x = Button.hx;
			*y = Button.hy;
			break;
		default:
			*x = -1;
			*y = -1;
			break;
		}
	}
	//ステージ選択時にピースを設置できないマスを設定します。
	void SetNotBoard(int x, int y) {
		if (x < TWidth + 1 && y < THeight + 1) {
			Table[x][y].board = -1;
		}
	}

	//ステージ選択時にプレイヤーが使用できないピースを設定します。
	void SetNotUse(int p) {
		if (p > 0 && p < PIECECOUNT + 1) {
			Player.play[p] = -1;			
		}
		Forbidden.rest++;
	}

	//ステージ選択時に予め盤面に設置されたピースを設定します。
	void SetOnBoard(int p, int x, int y, int angle) {		
		Player.play[p] = -1;
		Table[x][y].board = p + 100;
		int tx, ty;
		for (int fcount = 0; fcount < 4; fcount++) {
			tx = x;
			ty = y;
			switch (angle) {
			case 0://原型
				tx += Player.p[p].fan[fcount].x;
				ty += Player.p[p].fan[fcount].y;
				break;
			case 1://90度回転
				tx += Player.p[p].fan[fcount].y;
				ty += Player.p[p].fan[fcount].x * -1;
				break;
			case 2://180度回転
				tx += Player.p[p].fan[fcount].x * -1;
				ty += Player.p[p].fan[fcount].y * -1;
				break;
			case 3://270度回転
				tx += Player.p[p].fan[fcount].y * -1;
				ty += Player.p[p].fan[fcount].x;
				break;
			case 4://上下反転
				tx += Player.p[p].fan[fcount].x;
				ty += Player.p[p].fan[fcount].y * -1;
				break;
			case 5://上下反転 & 90度回転
				tx += Player.p[p].fan[fcount].y * -1;
				ty += Player.p[p].fan[fcount].x * -1;
				break;
			case 6://上下反転 & 180度回転
				tx += Player.p[p].fan[fcount].x * -1;
				ty += Player.p[p].fan[fcount].y;
				break;
			case 7://上下反転 & 270度回転
				tx += Player.p[p].fan[fcount].y;
				ty += Player.p[p].fan[fcount].x;
				break;
			}
			Table[tx][ty].board = p;
		}
		//Forbidden.rest++;		
	}

	//盤面にすべてのピースがセットされているかを調べます。全て使われていればtrueが帰ります。
	bool AllPieceSet() {
		
			int pcount = 0;
			for (int p = 1; p < PIECECOUNT + 1; p++) {
				if (Player.play[p] > 0) {
					pcount++;
				}
			}
			if (pcount == PIECECOUNT) {
				return true;
			}
			else {
				return false;
			}
		
	}

	//盤面が全て埋まっているかどうかを調べます。全て埋まっていればtrueが帰ります。
	bool AllTableSet() {

		for (int x = 1; x < TWidth + 1; x++) {
			for (int y = 1; y < THeight + 1; y++) {
				if (Table[x][y].board == 0) {
					return false; 
				}
			}
		}
		return true;
	}

	//ゲーム内のピースの柄を指定します。引数には画像ハンドルを指定します。デフォルトの場合は0を指定します。
	void SetStyle(int style) {
		if (style < 1) {
			Player.style = mino;
		}
		else {
			Player.style = style;
		}
	}
	struct PIECE {
		int x;
		int y;
	};
	struct MINO {
		int image;//イメージハンドル。原型として最初に読み込まれ、pent構造体から別の構造体へとコピー(初期化)された上で加工されます。		
		PIECE fan[5];//中心マスから見た他マスまでの直交距離。0～3まで扱う。4は画像左上から中心マスまでの直交座標距離(10の倍数)。中心マス座標と他マスとの距離からピース範囲を計算しクリックを判定する。
		char * name;//各ピースに付けられた名前。ヘキソミノの場合はなし。
		int angle;//各ピースのアングル。0.原型まま 1.90度回転 2.180度回転 3.270度回転 4.上下逆転 5.上下逆転＆90度回転 6.上下逆転＆180度回転(左右回転とも） 7.上下逆転＆270度回転
		int width;//画像の横幅
		int height;//画像の縦幅
	};
	MINO pent[PIECECOUNT + 1];//1～12までを扱う
	int shadow[PIECECOUNT + 1];//盤面にドラッグしたときに出るピースの影。設置可能な場合のみ表示される。
	struct pLAYER {

		MINO  p[13];//プレイヤーが操作しているピースの情報。NewGameではpentを元に初期化されます。
		PIECE set[13];//盤面に設置されたピースの座標。これが0の時は未設置状態を示す。いずれもピクセル単位とする。
		int play[13];//プレイヤーによって操作されたピースの順番。Undoメソッドではこれを参考に1手前の状態に戻す。0の時は未設置状態でchooseが0の時は待ちピース列に移動します。-1の時は禁止ないし既に設置されプレイヤーが操作できないことを示します。
					 //int order[13];//待ち行列での順番。1～12の昇順でメインピース枠に移動する。ダブルクリックで消去されたときや元に戻す時、手動で待ち行列に戻されたときには待ち行列の最後尾に回され、ほかピースの順番も更新されます。
		int np[13];//待ち行列での前順番。1～12の昇順でメインピース枠に移動する。ダブルクリックで消去されたときや元に戻す時、手動で待ち行列に戻されたときには待ち行列の最後尾に回され、ほかピースの順番も更新されます。
		int pp[13];//待ち行列での後順番。1～12の昇順でメインピース枠に移動する。ダブルクリックで消去されたときや元に戻す時、手動で待ち行列に戻されたときには待ち行列の最後尾に回され、ほかピースの順番も更新されます。
		int root;//待ち行列の先頭添字。
		int shadow[13];//設置可能なピースの影。プレイヤー操作によって影画像も変化するためNewGameで元のshadowからコピー＆初期化されます。
		int choose;//プレイヤーがピースをクリックし、選択状態にあるかどうかを示します。0.未選択時 1～12.選択状態でかつ選択されたピースの番号
		int cx;//選択状態にあるピースのX座標。盤面に設置されておらず画面上にある時の描写に利用されます。またマウス座標からこの値を引いた座標が常に描画位置になります。
		int cy;//選択状態にあるピースのY座標。盤面に設置されておらず画面上にある時の描写に利用されます。またマウス座標からこの値を引いた座標が常に描画位置になります。
		int mcx;//ピースがクリックされたX座標と画像の左上X座標との差
		int mcy;//ピースがクリックされたY座標と画像の左上Y座標との差
		int ablex;//設置可能な場所の左上X座標。選択状態のピースが盤面内にあるとき、盤面に設置可能な場合はその場所をピース範囲で色付けします。
		int abley;//設置可能な場所の左上Y座標。選択状態のピースが盤面内にあるとき、盤面に設置可能な場合はその場所をピース範囲で色付けします。
		int click;//マウスの状態。0.クリックされていない 1.シングルクリック 2.ダブルクリック 3.ドラッグ　4.クリックしたまま動かない
		int played;//プレイヤーによって設置されたピースの総数。この値から1手戻るボタン処理を行い、さらに設置済みピースのクリック時にplayの調整を行います。
		int style;//ピースの柄。デフォルトでは0だが、Settingにて指定される。
	};
	pLAYER Player;

	struct TABLE {
		int board;//盤面の状況を表す変数。0.空白マス 1～12.ピースが配置されたマス 1～12 + 100.ピースの中心マス -1.操作不能な固定マス
		int check;//ピース配置後、Checkメソッドで使われる変数。-1.空白マス 0.余白調査の必要なピース隣接マス 1～12.配置済ピースの中心マス 100.配置済ピース,固定マスまたは5以上の余白が確認された空白マス
	};
	TABLE Table[TWidth + 1][THeight + 1];//[1～10][1～6]を10×6の盤面とする。
protected:


	struct fORBIDDEN {
		bool revolution;//ピースの回転が禁止されいるかどうかを示します。trueの場合angle.0(原型),4(上下反転),6(左右反転)のみ有効となる。
		bool upset;//ピースの反転が禁止されているかどうかを示します。trueの場合angle0～3のみ有効となる。
		bool all;//ピースの回転と反転がいずれも禁止されているかを示します。trueの時は回転も反転も禁止されたangle.0,5,7のみ使用可能となり、問題ではangleが固定されます。
		int rest;//盤面に対する余剰ピース数。
		int initturn;//反転が禁止された際にステージ番号に応じて半数のピースを回転させる時の変数。0.前半,1.後半,2.偶数,3.奇数
	};
	fORBIDDEN Forbidden;

	struct operatebutton {
		int hx;//左右反転ボタンがある画像のX座標。禁止されているときは0になる。
		int hy;//左右反転ボタンがある画像のY座標。禁止されているときは0になる。
		int rx;//90度回転ボタンがある画像のX座標。禁止されているときは0になる。
		int ry;//90度回転ボタンがある画像のY座標。禁止されているときは0になる。
		int vx;//上下反転ボタンがある画像のX座標。禁止されているときは0になる。
		int vy;//上下反転ボタンがある画像のY座標。禁止されているときは0になる。
	};
	operatebutton Button;
	struct HINT {
		int image;
		int x;
		int y;
	};
	HINT hint[6];//NewGame後のGetHintで画像を作成し、DisplayBoardで表示
	short hintcount;//初期値は0でヒント1から5までを順番に表示する。5以上はない。
	int pcount;
	int checkspace;
	int agecorner;
	int cell;
	int nearcell;
	int evilcell;
	int display;//盤面を拡大するための空画像。
	int PieceRow;//ピースの待ち行列。メインピース枠と待ち枠に別れる。プレイヤーの利き腕によって配置が異なる。
	int mino;//ペントミノ1マス分を占めるピース。DisplayではTable.boardを参考にminoを敷き詰めてペントミノを表現する。
	int nextp;//メインピース枠内にあるピースを一旦除外し、待ちピース枠にあるピースを順順に移動させるためのボタンの画像。
	int neil;//最初から盤面に固定化されたピースかどうかを示すために中心点に描写されるネジ画像
	int button;//各種ボタン画像。上から1手戻す、最初から、Porse,ヒント
	int Turn;//90度回転ボタン。選択状態でない時はメインピース枠上部に、選択状態の時は選択されたピースの上部ないし下部に表示される。禁止された場合は描写されない。
	int UDreverse;//上下反転ボタン。選択状態でない時はメインピース枠上部に、選択状態の時は選択されたピースの上部ないし下部に表示される。禁止された場合は描写されない。
	int LRreverse;//左右反転ボタン。選択状態でない時はメインピース枠上部に、選択状態の時は選択されたピースの上部ないし下部に表示される。禁止された場合は描写されない。
	int buttonwait;//ボタンが押されてから指定されたフレーム秒間は再度ボタンを押すことを禁止する変数です。この変数が0以上の場合はボタンが動作しません。
};
class Sorting:public Pentomino {//盤面総当りの原始的なソートプログラム
public:
	Sorting::Sorting() {
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			Setpent[p].p = &pent[p];
			Setpent[p].choice = 0;
			Setpent[p].num = 0;
			Setpent[p].x = 0;
			Setpent[p].y = 0;
		}
		
	}

	void startsort(int stage) {
		int setrand[PIECECOUNT + 1];
		int rank[PIECECOUNT + 1];
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			setrand[p] = GetRand(100);
			rank[p] = p;
		}
		int temp;
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			for (int pp = 1; pp < 13; pp++) {
				if (setrand[p] <= setrand[pp]) {
					temp = rank[p];
					rank[p] = rank[pp];
					rank[pp] = temp;
				}
			}
		}
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			Setpent[p].choice = rank[p];
			Setpent[p].num = 0;
			Setpent[p].x = 0;
			Setpent[p].y = 0;
			History[p].p = 0;
			History[p].x = 0;
			History[p].y = 0;
			History[p].angle = 0;
			History[p].count = 0;
		}
		NewGame();
	}
	//特定の条件下で盤面をすべて埋められるかを調べます。全埋めに失敗した場合ないし何らかのエラーが発生した場合は-1が帰ります。ステージデータ作成用
	int sort() {
		int minp = 1;
		int minc = 1000000;
		int r = 0;
		for (int p = 1; p < 13; p++) {
			if (Setpent[p].choice < minc && Setpent[p].num == 0 && Setpent[p].choice > 0) {
				minc = Setpent[p].choice;//一番優先度の高いピースを選択する。
				minp = p;
				if (Setpent[p].choice > 100000) {
					return -1;
				}
			}
		}
		for (int angle = 0; angle < 8; angle++) {//原型から回転・反転を試みて盤面にセットできるかどうかを調べる。	
			bool Settable = true;
			if (Forbidden.revolution) {
				if (angle == 0 || angle == 4 || angle == 6) {
					Settable = true;
				}
				else {
					Settable = false;
				}
			}
			else {
				if (Forbidden.upset) {
					if (angle >= 0 && angle < 3) {
						Settable = true;
					}
					else {
						Settable = false;
					}
				}
				else {
					if (Forbidden.all) {
						if (angle == 0 || angle == 5 || angle == 7) {
							Settable = true;
						}
						else {
							Settable = false;
						}
					}
				}
			}
			if (Settable) {
				if (Setpent[minp].num > 0) {//ピースのセットが完了したらループを抜ける
					break;
				}
				for (int x = 1; x < TWidth + 1; x++) {
					for (int y = 1; y < THeight + 1; y++) {
						if (Table[x][y].board == 0) {
							Setpent[minp].x = x;
							Setpent[minp].y = y;
							Table[x][y].board = minp + 100;
							Setpent[minp].p->angle = angle;//ピースの状態を登録						
							Setpent[minp].num = SetPiece(minp, 0);
							if (Setpent[minp].num == -1) {
								//途中で失敗が発覚した場合はピースを盤面から削除し優先度を最後列に回す。
								Remove(minp);
							}
							if (Setpent[minp].num > 0) {//ピースのセットが完了したらCheckを実行し、隙間ができる(=falseが帰る)場合はRemoveを実行し別のangleを試す。
								if (Check() == false) {
									pcount--;
									Remove(minp);
								}
								else {
									if (History[pcount].p == minp && History[pcount].x == x && History[pcount].y == y && History[pcount].angle == angle) {
										//手が詰まる前の手番時と同じ置き方の場合はやり直し、別の置き方を試す。
										pcount--;
										Remove(minp);
									}
									else {
										History[pcount].p = minp;
										History[pcount].x = x;
										History[pcount].y = y;
										History[pcount].angle = angle;
										if (History[pcount].p == minp) {
											History[pcount].count++;
										}
										break;
									}
								}
							}
						}
					}
					if (Setpent[minp].num > 0) {
						break;
					}
				}
			}
		}
		if (Setpent[minp].num == 0) {
			/*/どこにも置けないピースが発生したときはひとつ前のピースを取り外し、次のSortでの最優先ピースとする。
			ただし盤面積＜ピース面積の時はその余剰ピース数に応じて猶予する。*/
			int rest = Forbidden.rest;
			for (int p = 1; p < PIECECOUNT + 1; p++) {
				if (Setpent[p].num == 0) { rest--; }
				if (rest == 0) { break; }
			}
			if (rest == 0) {
				int up = 1;
				while (Setpent[up].num != pcount && up < 13) {
					up++;
				}
				if (up != 13) {
					pcount--;
					Remove(up);
					Setpent[minp].choice %= 13;
				}
				else {
					return -1;
				}
			}
			else {
				Setpent[minp].choice += 13;
			}
		}
		for (int h = 1; h < 13; h++) {//同じ配置が5回続いた場合は2手前まで戻る。1手目では1手前までもどる。
			if (History[h].count > 5) {
				if (pcount > 1) {
					pcount -= 2;
					Remove(History[h].p);
					Remove(History[h - 1].p);
					for (int hh = h - 1; hh < h + 1; hh++) {
						History[h].p = 0;
						History[h].x = 0;
						History[h].y = 0;
						History[h].count = 0;
					}
				}
				else {
					pcount--;
					Remove(History[h].p);
					History[h].p = 0;
					History[h].x = 0;
					History[h].y = 0;
					History[h].count = 0;
				}
			}
		}
		//WaitTimer(100);
		return 0;
	}

	//ピースの他部分に該当するマスがいずれも空白であるかどうかを再帰的に調べます。ステージデータ作成用
	int SetPiece(int p, int fcount) {
		if (fcount == 4) {
			pcount++;
			return pcount;//ピース部分が全て埋まった場合はpcountを返す(Setpent[p].num = pcount)とする。
		}
		int px = Setpent[p].x;
		int py = Setpent[p].y;
		switch (Setpent[p].p->angle) {
		case 0://原型
			px += Setpent[p].p->fan[fcount].x;
			py += Setpent[p].p->fan[fcount].y;
			break;
		case 1://90度回転
			px += Setpent[p].p->fan[fcount].y;
			py += Setpent[p].p->fan[fcount].x * -1;
			break;
		case 2://180度回転
			px += Setpent[p].p->fan[fcount].x * -1;
			py += Setpent[p].p->fan[fcount].y * -1;
			break;
		case 3://270度回転
			px += Setpent[p].p->fan[fcount].y * -1;
			py += Setpent[p].p->fan[fcount].x;
			break;
		case 4://上下反転
			px += Setpent[p].p->fan[fcount].x;
			py += Setpent[p].p->fan[fcount].y * -1;
			break;
		case 5://上下反転 & 90度回転
			px += Setpent[p].p->fan[fcount].y * -1;
			py += Setpent[p].p->fan[fcount].x * -1;
			break;
		case 6://上下反転 & 180度回転
			px += Setpent[p].p->fan[fcount].x * -1;
			py += Setpent[p].p->fan[fcount].y;
			break;
		case 7://上下反転 & 270度回転
			px += Setpent[p].p->fan[fcount].y;
			py += Setpent[p].p->fan[fcount].x;
			break;
		}
		if (px < 1 || px > TWidth || py < 1 || py > THeight || Table[px][py].board != 0) {
			return -1;//ピースが盤面からはみ出るか既に別のピースが埋まっていた場合は失敗(num == 0とする)
		}
		else {
			Table[px][py].board = p;
			return SetPiece(p, fcount + 1);
		}
	}

	//盤面の状況を確認し、ピースを設置できないスペースがあるかどうかを確認します。ソート用
	bool Check() {
		bool r = true;
		for (int x = 1; x < TWidth + 1; x++) {
			for (int y = 1; y < THeight + 1; y++) {
				if (Table[x][y].board > 0) {
					if (Table[x][y].board > 100) {
						Table[x][y].check = Table[x][y].board - 100;
					}
					else {
						Table[x][y].check = 100;
					}
				}
				else {
					if (Table[x][y].board == -1) {
						Table[x][y].check = 100;
					}
					else {
						Table[x][y].check = -1;
					}
				}
			}
		}
		for (int x = 1; x < TWidth + 1; x++) {
			for (int y = 1; y < THeight + 1; y++) {
				if (Table[x][y].check == -1) {
					if (Table[x - 1][y].board > 0 || Table[x][y - 1].board > 0 || Table[x + 1][y].board > 0 || Table[x][y + 1].board > 0) {
						Table[x][y].check = 0;
					}
				}
			}
		}
		checkspace = 0;
		for (int x = 1; x < TWidth + 1; x++) {
			for (int y = 1; y < THeight + 1; y++) {
				if (Table[x][y].check == 0) {
					checkspace = 1;
					Table[x][y].check = 100;
					CheckSpace(x + 1, y);
					CheckSpace(x, y + 1);
					CheckSpace(x - 1, y);
					CheckSpace(x, y - 1);
					if (checkspace < (12 - pcount) * 5 && checkspace % 5 != 0) {
						for (int xx = 1; xx < TWidth + 1; xx++) {
							for (int yy = 1; yy < THeight + 1; yy++) {
								if (Table[xx][yy].check < 1 || Table[xx][yy].check == 100) {
									if (Table[xx - 1][yy].board > 0 || Table[xx][yy - 1].board > 0 || Table[xx + 1][yy].board > 0 || Table[xx][yy + 1].board > 0) {
										Table[xx][yy].check = 0;
									}
									else {
										Table[xx][yy].check = -1;
									}
								}
							}
						}
						return false;
					}
				}
				if (checkspace >= (12 - pcount) * 5) {
					break;
				}
			}
			if (checkspace >= (12 - pcount) * 5) {
				break;
			}
		}
		for (int x = 1; x < TWidth + 1; x++) {
			for (int y = 1; y < THeight + 1; y++) {
				if (Table[x][y].check < 1 || Table[x][y].check == 100) {
					if (Table[x - 1][y].board > 0 || Table[x][y - 1].board > 0 || Table[x + 1][y].board > 0 || Table[x][y + 1].board > 0) {
						Table[x][y].check = 0;
					}
					else {
						Table[x][y].check = -1;
					}
				}
			}
		}
		return r;
	}
	void CheckSpace(int sx, int sy) {//盤面のスペース数を数えます。
		if (sx < 1 || sx > TWidth || sy < 1 || sy > THeight || Table[sx][sy].check  > 0) {
			return;
		}
		else {
			checkspace++;
		}
		Table[sx][sy].check = 100;
		CheckSpace(sx + 1, sy);
		CheckSpace(sx, sy + 1);
		CheckSpace(sx - 1, sy);
		CheckSpace(sx, sy - 1);
		return;
	}

	//ピースを盤面から削除し優先度を最後列に回します。ソート用
	void Remove(int p) {
		Setpent[p].choice += 13;
		Setpent[p].num = 0;
		Setpent[p].x = 0;
		Setpent[p].y = 0;
		for (int x = 1; x < TWidth + 1; x++) {
			for (int y = 1; y < THeight + 1; y++) {
				if (Table[x][y].board == p || Table[x][y].board == p + 100) {
					Table[x][y].board = 0;
				}
			}
		}
	}

	void SetNotSort(int p) {
		Setpent[p].choice = -1;
		Setpent[p].num = -1;
		Setpent[p].x = -1;
		Setpent[p].y = -1;
		SetNotUse(p);
	}

	void SetOnSortBoard(int p, int x, int y, int angle) {
		Setpent[p].choice = -1;
		Setpent[p].num = -1;
		Setpent[p].x = x;
		Setpent[p].y = y;
		Setpent[p].p->angle = angle;
		int sx, sy;
		for (int f = 0; f < 4; f++) {
			sx = x;
			sy = y;
			switch (angle) {
			case 0:
				sx += Setpent[p].p->fan[f].x;
				sy += Setpent[p].p->fan[f].y;
				break;
			case 1:
				sx += Setpent[p].p->fan[f].y;
				sy += Setpent[p].p->fan[f].x * -1;
				break;
			case 2:
				sx += Setpent[p].p->fan[f].x * -1;
				sy += Setpent[p].p->fan[f].y * -1;
				break;
			case 3:
				sx += Setpent[p].p->fan[f].y * -1;
				sy += Setpent[p].p->fan[f].x;
				break;
			case 4:
				sx += Setpent[p].p->fan[f].x;
				sy += Setpent[p].p->fan[f].y * -1;
				break;
			case 5://上下反転 & 90度回転
				sx += Setpent[p].p->fan[f].y * -1;
				sy += Setpent[p].p->fan[f].x * -1;
				break;
			case 6://上下反転 & 180度回転
				sx += Setpent[p].p->fan[f].x * -1;
				sy += Setpent[p].p->fan[f].y;
				break;
			case 7://上下反転 & 270度回転
				sx += Setpent[p].p->fan[f].y;
				sy += Setpent[p].p->fan[f].x;
			}
			Table[sx][sy].board = p;
		}
		SetOnBoard(p, x, y, angle);
	}
	void DisplaySortBoard(bool righty) {
		for (int x = 20; x < 240; x += 10) {
			DrawGraph(x, 20, agecorner, false);
			DrawGraph(x, 150, agecorner, false);
		}
		for (int y = 30; y < 150; y += 10) {
			DrawGraph(20, y, agecorner, false);
			DrawGraph(230, y, agecorner, false);
		}
		int img;
		for (int x = 30; x < 230; x += 20) {
			for (int y = 30; y < 150; y += 20) {
				switch (Table[(int)((x - 10) / 20)][(int)((y - 10) / 20)].board) {
				case -1:
					img = evilcell;
					break;
				case 0:
					if (Table[(int)((x - 10) / 20)][(int)((y - 10) / 20)].check == -1) {
						img = cell;
					}
					else {
						img = nearcell;
					}
					break;
				default:
					img = mino;
					break;
				}
				DrawGraph(x, y, img, false);
				if (Table[(int)((x - 10) / 20)][(int)((y - 10) / 20)].board > 0) {
					int color = Table[(int)((x - 10) / 20)][(int)((y - 10) / 20)].board;
					if (color > 100) {
						color -= 100;
						DrawFormatString(x + 2, y + 2, GetColor(0, 0, 0), "%d", Player.play[color]);
					}
					switch (color) {
					case 1:
						color = GetColor(255, 0, 0);
						break;
					case 2:
						color = GetColor(255, 100, 0);
						break;
					case 3:
						color = GetColor(200, 200, 0);
						break;
					case 4:
						color = GetColor(100, 255, 0);
						break;
					case 5:
						color = GetColor(0, 255, 0);
						break;
					case 6:
						color = GetColor(0, 255, 100);
						break;
					case 7:
						color = GetColor(0, 200, 200);
						break;
					case 8:
						color = GetColor(0, 100, 255);
						break;
					case 9:
						color = GetColor(0, 0, 255);
						break;
					case 10:
						color = GetColor(100, 0, 255);
						break;
					case 11:
						color = GetColor(200, 0, 200);
						break;
					case 12:
						color = GetColor(255, 0, 100);
						break;
					}
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
					DrawBox(x + 1, y + 1, x + 19, y + 19, color, true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);

				}

			}
		}
		for (int p = 1; p < 13; p++) {
			if (Setpent[p].choice == -1 && Setpent[p].x != -1) {
				DrawGraph(Setpent[p].x * 20 + 10, Setpent[p].y * 20 + 10, neil, true);
			}
		}
		int r = GetDrawScreenGraph(20, 20, 240, 160, display);
		DrawExtendGraph(20, 20, 460, 300, display, false);
		for (int p = 1; p < 13; p++) {
			//盤面に設置されたピースを表示
			if (Player.set[p].x != 0) {
				//DrawGraph(Player.set[p].x, Player.set[p].y, Player.p[p].image, TRUE);
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				//DrawGraph(Player.set[p].x, Player.set[p].y, Player.shadow[p], TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
			}
			if (Player.root == 0 || Player.np[p] == 0) {
				p = p;
			}
		}

		for (int y = 19; y < 230; y += 70) {
			DrawGraph(489, y, button, true);
			switch ((y + 51) / 70) {
			case 1:
				DrawString(520, 37, "1手戻す", GetColor(0, 0, 0));
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawBox(491, y + 2, 609, y + 50, GetColor(200, 75, 75), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
				break;
			case 2:
				DrawString(520, y + 18, "最初から", GetColor(0, 0, 0));
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawBox(491, y + 2, 609, y + 50, GetColor(200, 200, 75), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
				break;
			case 3:
				DrawString(530, y + 18, "Porse", GetColor(0, 0, 0));
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawBox(491, y + 2, 609, y + 50, GetColor(75, 200, 75), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
				break;
			case 4:
				DrawString(530, y + 18, "ヒント", GetColor(0, 0, 0));
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawBox(491, y + 2, 609, y + 50, GetColor(75, 75, 200), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
				break;
			}
		}
		int count = (Player.choose == 0) ? 1 : 2;
		int pcount = 1;
		int pp;
		if (righty) {
			DrawTurnGraph(18, 318, PieceRow, true);
			for (int p = 1; p < 13; p++) {
				pp = Player.root;
				pcount = (Player.choose == 0) ? 1 : 2;
				while (pcount != count && pp < 13) {
					pp = Player.np[pp];
					pcount++;
				}
				if (pp < 13 && pcount < 6) {
					if (Player.choose != pp || Player.choose == 0) {//選択状態のピースは待ちピース枠に表示しない
						int width = Player.p[pp].width;
						int height = Player.p[pp].height;
						int x1, y1, x2, y2;
						switch (count) {
						case 1://120×120 445-565x 335-455y 505x395y
							x1 = 445;
							x2 = 565;
							y1 = 335;
							y2 = 455;
							switch (width) {//ミノ1つあたり40×40
							case 40:
								x1 += 48;
								x2 -= 48;
								break;
							case 80:
								if (height == 160) {
									x1 += 30;
									x2 -= 30;
								}
								else {
									x1 += 20;
									x2 -= 20;
								}
								break;
							}
							switch (height) {//ミノ1つあたり40×40
							case 40:
								y1 += 48;
								y2 -= 48;
								break;
							case 80:
								if (width == 160) {
									y1 += 30;
									y2 -= 30;
								}
								else {
									y1 += 20;
									y2 -= 20;
								}
								break;
							}
							DrawExtendGraph(x1, y1, x2, y2, Player.p[pp].image, true);
							if ((pcount == 1 || Player.choose == 0) && AllTableSet() == false) {
								if (Forbidden.revolution == false) {
									Button.rx = 435;
									Button.ry = 265;
									SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
									DrawBox(Button.rx, Button.ry, Button.rx + 50, Button.ry + 50, GetColor(150, 150, 50), true);
									SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
									DrawGraph(430, 265, Turn, true);
								}
								else {
									Button.rx = 0;
									Button.ry = 0;
								}
								if (Forbidden.upset == false) {
									Button.vx = 485;
									Button.vy = 265;
									Button.hx = 535;
									Button.hy = 265;
									SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
									DrawBox(Button.vx, Button.vy, Button.vx + 50, Button.vy + 50, GetColor(50, 50, 200), true);
									DrawBox(Button.hx, Button.hy, Button.hx + 50, Button.hy + 50, GetColor(50, 200, 50), true);
									SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
									DrawGraph(485, 265, UDreverse, true);
									DrawGraph(535, 265, LRreverse, true);
								}
								else {
									Button.hx = 0;
									Button.hy = 0;
									Button.vx = 0;
									Button.vy = 0;
								}
							}
							break;
						case 2:
							x1 = 370;
							x2 = 420;
							y1 = 370;
							y2 = 420;

							break;
						case 3:
							x1 = 300;
							x2 = 350;
							y1 = 370;
							y2 = 420;
							break;
						case 4:
							x1 = 230;
							x2 = x1 + 50;
							y1 = 370;
							y2 = y1 + 50;
							break;
						case 5:
							x1 = 160;
							x2 = x1 + 50;
							y1 = 370;
							y2 = y1 + 50;
							break;
						}
						if (count > 1) {
							switch (width) {//ミノ1つあたり10×10
							case 40:
								x1 += 20;
								x2 -= 20;
								break;
							case 80:
								if (height == 160) {//12.5×4
									x1 += 12;
									x2 -= 12;
								}
								else {
									x1 += 8;
									x2 -= 8;
								}
								break;
							}
							switch (height) {//ミノ1つあたり10×10
							case 40:
								y1 += 20;
								y2 -= 20;
								break;
							case 80:
								if (width == 160) {
									y1 += 12;
									y2 -= 12;
								}
								else {
									y1 += 8;
									y2 -= 8;
								}
								break;
							}
							int r = DrawExtendGraph(x1, y1, x2, y2, Player.p[pp].image, true);
							if (r == -1) {
								r = -1;
							}
						}
					}
					count++;
					if (count == 6) {
						break;
					}
				}
				else {
					//break;
				}
			}
		}
		else {

		}

		if (Player.choose > 0) {
			if (Player.ablex != 0) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawGraph(Player.ablex, Player.abley, Player.shadow[Player.choose], TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);

			}
			DrawGraph(Player.cx, Player.cy, Player.p[Player.choose].image, true);
			if (Player.click != 3) {
				int longer = (Player.p[Player.choose].width > Player.p[Player.choose].height) ? Player.p[Player.choose].width : Player.p[Player.choose].height;
				if (Player.cy < 80) {
					//各種ボタンをピースの下部に表示
					if (Forbidden.revolution == false) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
						DrawBox(Button.rx, Button.ry, Button.rx + 50, Button.ry + 50, GetColor(150, 150, 50), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
						DrawGraph(Button.rx, Button.ry, Turn, true);
					}
					else {
						Button.rx = 0;
						Button.ry = 0;
					}
					if (Forbidden.upset == false) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
						DrawBox(Button.vx, Button.vy, Button.vx + 50, Button.vy + 50, GetColor(50, 50, 200), true);
						DrawBox(Button.hx, Button.hy, Button.hx + 50, Button.hy + 50, GetColor(50, 200, 50), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
						DrawGraph(Button.vx, Button.vy, UDreverse, true);
						DrawGraph(Button.hx, Button.hy, LRreverse, true);
					}
					else {
						Button.vx = 0;
						Button.vy = 0;
						Button.hx = 0;
						Button.hy = 0;
					}

				}
				else {
					//各種ボタンをピースの上部に表示 -15 +40 +95 , -90
					if (Forbidden.revolution == false) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
						DrawBox(Button.rx, Button.ry, Button.rx + 50, Button.ry + 50, GetColor(150, 150, 50), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 150);
						DrawGraph(Button.rx, Button.ry, Turn, true);
					}
					else {
						Button.rx = 0;
						Button.ry = 0;
					}
					if (Forbidden.upset == false) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
						DrawBox(Button.vx, Button.vy, Button.vx + 50, Button.vy + 50, GetColor(50, 50, 200), true);
						DrawBox(Button.hx, Button.hy, Button.hx + 50, Button.hy + 50, GetColor(50, 200, 50), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 150);
						DrawGraph(Button.vx, Button.vy, UDreverse, true);
						DrawGraph(Button.hx, Button.hy, LRreverse, true);
					}
					else {
						Button.vx = 0;
						Button.vy = 0;
						Button.hx = 0;
						Button.hy = 0;
					}

				}
			}
			else {
				if (Player.cy < 80) {
					if (Forbidden.revolution == false) {
						Button.rx = Player.cx + Player.p[Player.choose].width / 2 - 73;
						Button.ry = Player.cy + Player.p[Player.choose].height + 5;
					}
					else {
						Button.rx = 0;
						Button.ry = 0;
					}
					if (Forbidden.upset == false) {
						Button.vx = Player.cx + +Player.p[Player.choose].width / 2 - 23;
						Button.vy = Player.cy + Player.p[Player.choose].height + 5;
						Button.hx = Player.cx + +Player.p[Player.choose].width / 2 + 27;
						Button.hy = Player.cy + Player.p[Player.choose].height + 5;
					}
					else {
						Button.vx = 0;
						Button.vy = 0;
						Button.hx = 0;
						Button.hy = 0;
					}

				}
				else {
					if (Forbidden.revolution == false) {
						Button.rx = Player.cx + Player.p[Player.choose].width / 2 - 73;
						Button.ry = Player.cy - 60;
					}
					else {
						Button.rx = 0;
						Button.ry = 0;
					}
					if (Forbidden.upset == false) {
						Button.vx = Player.cx + Player.p[Player.choose].width / 2 - 23;
						Button.vy = Player.cy - 60;
						Button.hx = Player.cx + Player.p[Player.choose].width / 2 + 27;
						Button.hy = Player.cy - 60;
					}
					else {
						Button.vx = 0;
						Button.vy = 0;
						Button.hx = 0;
						Button.hy = 0;
					}
				}

			}
		}
		if (buttonwait > 0) {
			buttonwait--;
		}
		//DrawFormatString(100, 100, GetColor(0, 0, 0), "cx = %d", Player.cx);
		//DrawFormatString(100, 130, GetColor(0, 0, 0), "cy = %d", Player.cy);
		//WaitKey();
	}
	bool AllPieceSortSet() {
		int max = 0;
		int finalp = 1;
		for (int p = 1; p < 13; p++) {
			if (Setpent[p].choice > max) {
				max = Setpent[p].choice;
				finalp = p;
			}
		}
		if (Setpent[finalp].num > 0) {
			return true;
		}
		else {
			return AllPieceSet();
		}
	}
private:
	struct sETPENT {
		MINO  * p;//各ピース構造体へのポインタ。
		int choice;//ピースをはめ込む順番。1～12までを扱いランダムに決定される。ソート中配置に失敗した場合は+13され後回しになる。0.プレイヤーによって設置済。 -1.盤面に最初から設置済または使用できない
		int num;//ピースがはめ込まれた順番を示す。盤面の手詰まり時や正解ルート探索時のやり直しに使われる。またSetpiece[12].setnum > 0は盤面に全ピースが埋まったことを示す。0.未設置状態 1～12.Sortにて設置状態 100 + 1～12.プレイヤーによる設置
		int x;//ボードでの中心マスのX座標。10×6の場合1～10まで。-1の場合は使用できないことを示す。
		int y;//ボードでの中心マスのY座標。10×6の場合1～6まで。-1の場合は使用できないことを示す。
	};
	sETPENT Setpent[PIECECOUNT + 1];//1～12までを扱う

	struct hISTORY {
		int p;
		int x;
		int y;
		int angle;
		int count;
	};
	hISTORY History[PIECECOUNT + 1];//ピースを設置した順番と位置・アングルを記録します。これはピースが設置される事に記録され、ピース埋めのやり直し時に利用されます。
};
class Sort2 :public Pentomino {//ピース・盤面位置・アングル毎に設置可能パターンを収集し、そこからランダム選択するソートプログラム
public:
	//bapのテーブル添字を盤面X横幅添字に変換
	int bx(int b) {//1～60
		if (b > 0 && b < TWidth * THeight + 1) {
			int bb = b % TWidth;
			if (bb == 0) { bb = TWidth; }
			return bb;
		}
		else {
			return -1;
		}
	}
	//bapのテーブル添字を盤面Y縦幅添字に変換
	int by(int b) {
		if (b > 0 && b < TWidth * THeight + 1) {
			return (int)((b - 1)/ TWidth) + 1;
		}
		else {
			return -1;
		}
	}

	void sort() {
		SortNotsetPattern();
		
		int lot;//各フェーズにてランダム抽選されるパターン数です。
		int pat = 0;//設置対象パターンの総数。
		int ppat;//ppat != patとなることで設置対象マスかどうかを抽出する。
		candidate ccan[1000];
		int cc = 1;
		for (int c = 1; c < 1000; c++) {
			if (can[c].adopted) {
				ccan[cc].a = can[c].a;
				ccan[cc].b = can[c].b;
				ccan[cc].p = can[c].p;
				ccan[cc].adopted = true;
				ccan[cc].phase = can[c].phase;
				cc++;
				pat++;
			}
			can[c].b = 0;
			can[c].a = 0;
			can[c].p = 0;
			can[c].adopted = false;
			can[c].phase = 0;
		}
		for (int c = 1; c < cc; c++) {
			can[c].b = ccan[c].b;
			can[c].a = ccan[c].a;
			can[c].p = ccan[c].p;
			can[c].adopted = ccan[c].adopted;
			can[c].phase = ccan[c].phase;
		}
		int prepat = pat;
		//設置候補となるマスを探索し、そこにある設置パターンをcanに収集していく
		for (int x = 1; x < TWidth + 1; x++) {
			for (int y = 1; y < THeight + 1; y++) {
				ppat = pat;
				for (int sx = x - 1; sx < x + 2; sx++) {
					for (int sy = y - 1; sy < y + 2; sy++) {
						if (sx < 1 || sx > TWidth || sy < 1 || sy > THeight || Table[sx][sy].board != 0) {
							pat++;
							break;
						}
					}
					if (ppat != pat) { break; }
				}
				if (ppat != pat) {
					//Table[x][y]の周囲8マスのいずれかが空白ではなく、設置対象となったとき
					int b = x + (y - 1) * TWidth;
					for (int p = 1; p < PIECECOUNT + 1; p++) {
						for (int a = 0; a < 8; a++) {
							if (bap[b][a][p] == false) {
								//設置可能パターンの登録・収集
								can[pat].b = b;
								can[pat].a = a;
								can[pat].p = p;
								can[pat].adopted = false;
								can[pat].phase = phase;
								if (pat > 998) {
									pat = 1;
								}
								pat++;
							}
						}
					}
					pat--;
				}
			}
		}
		//設置可能パターンがないか設置可能パターンが無いピースが余剰ピース数より多い場合は2つ前のフェーズに戻る
		int notsetcount = notsetpiece();
		int prep = restp;
		if (notsetcount < 0 || pat == 0 || prepat == pat) {
			for (int pa = 1; pa < 1000; pa++) {
				if (can[pa].phase > phase - 2) {
					Remove(can[pa].p);
					can[pa].adopted = false;
					Player.play[can[pa].p] = 0;
					restp++;
					if (restp > PIECECOUNT - Forbidden.rest) {
						restp = PIECECOUNT - Forbidden.rest;
					}
				}
			}
			phase -= 2;
		}
		else {
			//収集されたパターンの中から(lot数に応じたランダム|最も少ないパターン数のマス）を抽出する。
			if (restp >= PIECECOUNT / 3 * 2) {
				lot = (int)(restp / 4);
				int rd = 0;
				
				int l = 1;
				int limit = 0;
				while (l < lot + 1 && limit < pat) {					
					rd = GetRand(pat);
					int es = 0;
					/*if (phase == 0) {
						int minp = 0;
						int mincan = 99999;
						for (int p = 1; p < PIECECOUNT + 1; p++) {
							if (ppatcount[p] < mincan && ppatcount[p] > 0) {
								mincan = ppatcount[p];
								minp = p;
							}
						}
						while (can[rd].p != minp && es < 100) {
							rd = GetRand(pat);
						}
					}*/
					if (Player.play[can[rd].p] == 0 && can[rd].adopted == false && es < 100) {
						int tx = bx(can[rd].b);
						int ty = by(can[rd].b);
						if (Table[tx][ty].board == 0) {
							Table[tx][ty].board = 100 + can[rd].p;
							int a = can[rd].a;
							int p = can[rd].p;
							bool same = false;
							for (int fcount = 0; fcount < 4; fcount++) {
								switch (a) {
								case 0://原型
									tx += Player.p[p].fan[fcount].x;
									ty += Player.p[p].fan[fcount].y;
									break;
								case 1://90度回転
									tx += Player.p[p].fan[fcount].y;
									ty += Player.p[p].fan[fcount].x * -1;
									break;
								case 2://180度回転
									tx += Player.p[p].fan[fcount].x * -1;
									ty += Player.p[p].fan[fcount].y * -1;
									break;
								case 3://270度回転
									tx += Player.p[p].fan[fcount].y * -1;
									ty += Player.p[p].fan[fcount].x;
									break;
								case 4://上下反転
									tx += Player.p[p].fan[fcount].x;
									ty += Player.p[p].fan[fcount].y * -1;
									break;
								case 5://上下反転 & 90度回転
									tx += Player.p[p].fan[fcount].y * -1;
									ty += Player.p[p].fan[fcount].x * -1;
									break;
								case 6://上下反転 & 180度回転
									tx += Player.p[p].fan[fcount].x * -1;
									ty += Player.p[p].fan[fcount].y;
									break;
								case 7://上下反転 & 270度回転
									tx += Player.p[p].fan[fcount].y;
									ty += Player.p[p].fan[fcount].x;
									break;
								}
								if (Table[tx][ty].board != 0) {
									same = true;
									break;
								}
								else {
									Table[tx][ty].board = can[rd].p;
									tx = bx(can[rd].b);
									ty = by(can[rd].b);
								}
							}
							if (Check() && same == false) {
								can[rd].adopted = true;     //これら二つの処理は同判定に思えるが前者はランダム数の被り防止の判定、
								Player.play[can[rd].p] = -1;//後者のPlayer.playの処理は後のSortNotsetPatternのアップデートとしての処理である。
								can[rd].phase = phase;
								restp--;
								l++;
								SortNotsetPattern();
							}
							else {
								Remove(p);
								can[rd].adopted = false;
								Player.play[can[rd].p] = 0;
							}
						}
					}					
					limit++;
				}
				if (limit < pat) {
					phase++;
				}
			}
			else {
				lot = 1;
				//残数が1/3を切った段階で全盤面のうち設置可能パターンが最も少ないマスを優先的に設置していく next;	
				bool only = false;
				for (int x = 1; x < TWidth + 1; x++) {
					for (int y = 1; y < THeight + 1; y++) {
						if (onlypat[x][y].b != 0) {
							int rd = 1;
							while (rd < pat) {
								if (can[rd].b == onlypat[x][y].b && can[rd].a == onlypat[x][y].a && can[rd].p == onlypat[x][y].p) {
									SetOnePieceSort(rd);
									break;
								}
								rd++;
							}
						}
					}
				}
				if (only == false) {
					//一つしかないパターンがない時はランダムでひとつの設置パターンを採用する。
					int rd = GetRand(pat);
					if (Player.play[can[rd].p] == 0 && can[rd].adopted == false) {
						SetOnePieceSort(rd);
					}
				}
			}
		}
		//DisplaySortBoard(true);
		//DrawFormatString(50, 300, GetColor(0, 0, 0), "phase = %d", phase);
		//DrawFormatString(50, 320, GetColor(0, 0, 0), "pat  = %d", pat);
		DrawFormatString(50, 340, GetColor(0, 0, 0), "restp  = %d", restp);
		//}
		if (restp == 0/*phase > 2 && prep != restp*/) {
			//WaitKey();
		}
		int a = 0;
	}
	//ピースを一つだけ盤面に設置します。設置できない時や、設置後に手詰まりが明確になる場合は設置されません。
	void SetOnePieceSort(int rd) {
		int tx = bx(can[rd].b);
		int ty = by(can[rd].b);
		if (Table[tx][ty].board == 0) {
			Table[tx][ty].board = 100 + can[rd].p;
			int a = can[rd].a;
			int p = can[rd].p;
			bool same = false;
			for (int fcount = 0; fcount < 4; fcount++) {
				switch (a) {
				case 0://原型
					tx += Player.p[p].fan[fcount].x;
					ty += Player.p[p].fan[fcount].y;
					break;
				case 1://90度回転
					tx += Player.p[p].fan[fcount].y;
					ty += Player.p[p].fan[fcount].x * -1;
					break;
				case 2://180度回転
					tx += Player.p[p].fan[fcount].x * -1;
					ty += Player.p[p].fan[fcount].y * -1;
					break;
				case 3://270度回転
					tx += Player.p[p].fan[fcount].y * -1;
					ty += Player.p[p].fan[fcount].x;
					break;
				case 4://上下反転
					tx += Player.p[p].fan[fcount].x;
					ty += Player.p[p].fan[fcount].y * -1;
					break;
				case 5://上下反転 & 90度回転
					tx += Player.p[p].fan[fcount].y * -1;
					ty += Player.p[p].fan[fcount].x * -1;
					break;
				case 6://上下反転 & 180度回転
					tx += Player.p[p].fan[fcount].x * -1;
					ty += Player.p[p].fan[fcount].y;
					break;
				case 7://上下反転 & 270度回転
					tx += Player.p[p].fan[fcount].y;
					ty += Player.p[p].fan[fcount].x;
					break;
				}
				if (Table[tx][ty].board != 0) {
					same = true;
					break;
				}
				else {
					Table[tx][ty].board = can[rd].p;
					tx = bx(can[rd].b);
					ty = by(can[rd].b);
				}
			}			
			if (Check() && same == false) {
				can[rd].adopted = true;     //これら二つの処理は同判定に思えるが前者はランダム数の被り防止の判定、
				Player.play[can[rd].p] = -1;//後者のPlayer.playの処理は後のSortNotsetPatternのアップデートとしての処理である。
				can[rd].phase = phase;				
				SortNotsetPattern();
				int notset = notsetpiece();
				if (notset < 0) {
					Remove(p);
					
					can[rd].adopted = false;
					Player.play[can[rd].p] = 0;
				}
				else {
					restp--;
					phase++;
				}
			}
			else {
				Remove(p);
				can[rd].adopted = false;
				Player.play[can[rd].p] = 0;
			}
		}
	}
	//ソート中の盤面状況を画面に表示します。
	void DisplaySortBoard(bool righty) {
		for (int x = 20; x < 240; x += 10) {
			DrawGraph(x, 20, agecorner, false);
			DrawGraph(x, 150, agecorner, false);
		}
		for (int y = 30; y < 150; y += 10) {
			DrawGraph(20, y, agecorner, false);
			DrawGraph(230, y, agecorner, false);
		}
		int img;
		for (int x = 30; x < 230; x += 20) {
			for (int y = 30; y < 150; y += 20) {
				switch (Table[(int)((x - 10) / 20)][(int)((y - 10) / 20)].board) {
				case -1:
					img = evilcell;
					break;
				case 0:
					if (Table[(int)((x - 10) / 20)][(int)((y - 10) / 20)].check == -1) {
						img = cell;
					}
					else {
						img = nearcell;
					}
					break;
				default:
					img = mino;
					break;
				}
				DrawGraph(x, y, img, false);
				int c = GetColor(0, 0, 0);
				if (cant[(int)((x - 10) / 20)][(int)((y - 10) / 20)] == 0 && Table[(int)((x - 10) / 20)][(int)((y - 10) / 20)].board == 0) {
					c = GetColor(255, 0, 0);
				}
				//DrawFormatString(x + 2, y + 2, GetColor(0, 0, 0), "%d", bpatcount[(int)((x - 10) / 20) + (int)((y - 30) / 2)]);
				DrawFormatString(x + 2, y + 2, c, "%d", cant[(int)((x - 10) / 20)][(int)((y - 10) / 20)]);
				if (Table[(int)((x - 10) / 20)][(int)((y - 10) / 20)].board > 0) {
					int color = Table[(int)((x - 10) / 20)][(int)((y - 10) / 20)].board;
					if (color > 100) {
						color -= 100;
						DrawFormatString(x + 2, y + 2, GetColor(0, 0, 0), "%d", ppatcount[color]);
					}
					switch (color) {
					case 1:
						color = GetColor(255, 0, 0);
						break;
					case 2:
						color = GetColor(255, 100, 0);
						break;
					case 3:
						color = GetColor(200, 200, 0);
						break;
					case 4:
						color = GetColor(100, 255, 0);
						break;
					case 5:
						color = GetColor(0, 255, 0);
						break;
					case 6:
						color = GetColor(0, 255, 100);
						break;
					case 7:
						color = GetColor(0, 200, 200);
						break;
					case 8:
						color = GetColor(0, 100, 255);
						break;
					case 9:
						color = GetColor(0, 0, 255);
						break;
					case 10:
						color = GetColor(100, 0, 255);
						break;
					case 11:
						color = GetColor(200, 0, 200);
						break;
					case 12:
						color = GetColor(255, 0, 100);
						break;
					}
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
					DrawBox(x + 1, y + 1, x + 19, y + 19, color, true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);

				}

			}
		}

		int r = GetDrawScreenGraph(20, 20, 240, 160, display);
		DrawExtendGraph(20, 20, 460, 300, display, false);
		for (int p = 1; p < 13; p++) {
			//盤面に設置されたピースを表示
			if (Player.set[p].x != 0) {
				//DrawGraph(Player.set[p].x, Player.set[p].y, Player.p[p].image, TRUE);
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				//DrawGraph(Player.set[p].x, Player.set[p].y, Player.shadow[p], TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
			}
			if (Player.root == 0 || Player.np[p] == 0) {
				p = p;
			}
		}

		for (int y = 19; y < 230; y += 70) {
			DrawGraph(489, y, button, true);
			switch ((y + 51) / 70) {
			case 1:
				DrawString(520, 37, "1手戻す", GetColor(0, 0, 0));
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawBox(491, y + 2, 609, y + 50, GetColor(200, 75, 75), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
				break;
			case 2:
				DrawString(520, y + 18, "最初から", GetColor(0, 0, 0));
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawBox(491, y + 2, 609, y + 50, GetColor(200, 200, 75), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
				break;
			case 3:
				DrawString(530, y + 18, "Porse", GetColor(0, 0, 0));
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawBox(491, y + 2, 609, y + 50, GetColor(75, 200, 75), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
				break;
			case 4:
				DrawString(530, y + 18, "ヒント", GetColor(0, 0, 0));
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawBox(491, y + 2, 609, y + 50, GetColor(75, 75, 200), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
				break;
			}
		}
		int count = (Player.choose == 0) ? 1 : 2;
		int pcount = 1;
		int pp;
		if (righty) {
			DrawTurnGraph(18, 318, PieceRow, true);
			for (int p = 1; p < 13; p++) {
				pp = Player.root;
				pcount = (Player.choose == 0) ? 1 : 2;
				while (pcount != count && pp < 13) {
					pp = Player.np[pp];
					pcount++;
				}
				if (pp < 13 && pcount < 6) {
					if (Player.choose != pp || Player.choose == 0) {//選択状態のピースは待ちピース枠に表示しない
						int width = Player.p[pp].width;
						int height = Player.p[pp].height;
						int x1, y1, x2, y2;
						switch (count) {
						case 1://120×120 445-565x 335-455y 505x395y
							x1 = 445;
							x2 = 565;
							y1 = 335;
							y2 = 455;
							switch (width) {//ミノ1つあたり40×40
							case 40:
								x1 += 48;
								x2 -= 48;
								break;
							case 80:
								if (height == 160) {
									x1 += 30;
									x2 -= 30;
								}
								else {
									x1 += 20;
									x2 -= 20;
								}
								break;
							}
							switch (height) {//ミノ1つあたり40×40
							case 40:
								y1 += 48;
								y2 -= 48;
								break;
							case 80:
								if (width == 160) {
									y1 += 30;
									y2 -= 30;
								}
								else {
									y1 += 20;
									y2 -= 20;
								}
								break;
							}
							DrawExtendGraph(x1, y1, x2, y2, Player.p[pp].image, true);
							if (pcount == 1 || Player.choose == 0) {
								if (Forbidden.revolution == false) {
									Button.rx = 435;
									Button.ry = 265;
									SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
									DrawBox(Button.rx, Button.ry, Button.rx + 50, Button.ry + 50, GetColor(150, 150, 50), true);
									SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
									DrawGraph(430, 265, Turn, true);
								}
								else {
									Button.rx = 0;
									Button.ry = 0;
								}
								if (Forbidden.upset == false) {
									Button.vx = 485;
									Button.vy = 265;
									Button.hx = 535;
									Button.hy = 265;
									SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
									DrawBox(Button.vx, Button.vy, Button.vx + 50, Button.vy + 50, GetColor(50, 50, 200), true);
									DrawBox(Button.hx, Button.hy, Button.hx + 50, Button.hy + 50, GetColor(50, 200, 50), true);
									SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
									DrawGraph(485, 265, UDreverse, true);
									DrawGraph(535, 265, LRreverse, true);
								}
								else {
									Button.hx = 0;
									Button.hy = 0;
									Button.vx = 0;
									Button.vy = 0;
								}
							}
							break;
						case 2:
							x1 = 370;
							x2 = 420;
							y1 = 370;
							y2 = 420;

							break;
						case 3:
							x1 = 300;
							x2 = 350;
							y1 = 370;
							y2 = 420;
							break;
						case 4:
							x1 = 230;
							x2 = x1 + 50;
							y1 = 370;
							y2 = y1 + 50;
							break;
						case 5:
							x1 = 160;
							x2 = x1 + 50;
							y1 = 370;
							y2 = y1 + 50;
							break;
						}
						if (count > 1) {
							switch (width) {//ミノ1つあたり10×10
							case 40:
								x1 += 20;
								x2 -= 20;
								break;
							case 80:
								if (height == 160) {//12.5×4
									x1 += 12;
									x2 -= 12;
								}
								else {
									x1 += 8;
									x2 -= 8;
								}
								break;
							}
							switch (height) {//ミノ1つあたり10×10
							case 40:
								y1 += 20;
								y2 -= 20;
								break;
							case 80:
								if (width == 160) {
									y1 += 12;
									y2 -= 12;
								}
								else {
									y1 += 8;
									y2 -= 8;
								}
								break;
							}
							int r = DrawExtendGraph(x1, y1, x2, y2, Player.p[pp].image, true);
							if (r == -1) {
								r = -1;
							}
						}
					}
					count++;
					if (count == 6) {
						break;
					}
				}
				else {
					//break;
				}
			}
		}
		else {

		}

		if (Player.choose > 0) {
			if (Player.ablex != 0) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
				DrawGraph(Player.ablex, Player.abley, Player.shadow[Player.choose], TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);

			}
			DrawGraph(Player.cx, Player.cy, Player.p[Player.choose].image, true);
			if (Player.click != 3) {
				int longer = (Player.p[Player.choose].width > Player.p[Player.choose].height) ? Player.p[Player.choose].width : Player.p[Player.choose].height;
				if (Player.cy < 80) {
					//各種ボタンをピースの下部に表示
					if (Forbidden.revolution == false) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
						DrawBox(Button.rx, Button.ry, Button.rx + 50, Button.ry + 50, GetColor(150, 150, 50), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
						DrawGraph(Button.rx, Button.ry, Turn, true);
					}
					else {
						Button.rx = 0;
						Button.ry = 0;
					}
					if (Forbidden.upset == false) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
						DrawBox(Button.vx, Button.vy, Button.vx + 50, Button.vy + 50, GetColor(50, 50, 200), true);
						DrawBox(Button.hx, Button.hy, Button.hx + 50, Button.hy + 50, GetColor(50, 200, 50), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
						DrawGraph(Button.vx, Button.vy, UDreverse, true);
						DrawGraph(Button.hx, Button.hy, LRreverse, true);
					}
					else {
						Button.vx = 0;
						Button.vy = 0;
						Button.hx = 0;
						Button.hy = 0;
					}

				}
				else {
					//各種ボタンをピースの上部に表示 -15 +40 +95 , -90
					if (Forbidden.revolution == false) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
						DrawBox(Button.rx, Button.ry, Button.rx + 50, Button.ry + 50, GetColor(150, 150, 50), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 150);
						DrawGraph(Button.rx, Button.ry, Turn, true);
					}
					else {
						Button.rx = 0;
						Button.ry = 0;
					}
					if (Forbidden.upset == false) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
						DrawBox(Button.vx, Button.vy, Button.vx + 50, Button.vy + 50, GetColor(50, 50, 200), true);
						DrawBox(Button.hx, Button.hy, Button.hx + 50, Button.hy + 50, GetColor(50, 200, 50), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 150);
						DrawGraph(Button.vx, Button.vy, UDreverse, true);
						DrawGraph(Button.hx, Button.hy, LRreverse, true);
					}
					else {
						Button.vx = 0;
						Button.vy = 0;
						Button.hx = 0;
						Button.hy = 0;
					}

				}
			}
			else {
				if (Player.cy < 80) {
					if (Forbidden.revolution == false) {
						Button.rx = Player.cx + Player.p[Player.choose].width / 2 - 73;
						Button.ry = Player.cy + Player.p[Player.choose].height + 5;
					}
					else {
						Button.rx = 0;
						Button.ry = 0;
					}
					if (Forbidden.upset == false) {
						Button.vx = Player.cx + +Player.p[Player.choose].width / 2 - 23;
						Button.vy = Player.cy + Player.p[Player.choose].height + 5;
						Button.hx = Player.cx + +Player.p[Player.choose].width / 2 + 27;
						Button.hy = Player.cy + Player.p[Player.choose].height + 5;
					}
					else {
						Button.vx = 0;
						Button.vy = 0;
						Button.hx = 0;
						Button.hy = 0;
					}

				}
				else {
					if (Forbidden.revolution == false) {
						Button.rx = Player.cx + Player.p[Player.choose].width / 2 - 73;
						Button.ry = Player.cy - 60;
					}
					else {
						Button.rx = 0;
						Button.ry = 0;
					}
					if (Forbidden.upset == false) {
						Button.vx = Player.cx + Player.p[Player.choose].width / 2 - 23;
						Button.vy = Player.cy - 60;
						Button.hx = Player.cx + Player.p[Player.choose].width / 2 + 27;
						Button.hy = Player.cy - 60;
					}
					else {
						Button.vx = 0;
						Button.vy = 0;
						Button.hx = 0;
						Button.hy = 0;
					}
				}

			}
		}
		if (buttonwait > 0) {
			buttonwait--;
		}
		//DrawFormatString(100, 100, GetColor(0, 0, 0), "cx = %d", Player.cx);
		//DrawFormatString(100, 130, GetColor(0, 0, 0), "cy = %d", Player.cy);
		//WaitKey();
	}
	//ソートの準備
	void startsort(int stage) {
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			for (int b = 1; b < TWidth * THeight + 1; b++) {
				for (int a = 0; a < 8; a++) {
					//bapの初期化
					bap[b][a][p] = false;
				}
			}
		}
		for (int c = 1; c < 999; c++) {
			//can(設置可能パターン情報)の初期化
			can[c].b = 0;
			can[c].a = 0;
			can[c].p = 0;
			can[c].adopted = 0;
			can[c].phase = 0;
		}

		NewGame();
		
		//初期設定を元に設置不可パターンを設定
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			for (int b = 1; b < TWidth * THeight + 1; b++) {
				for (int a = 0; a < 8; a++) {

					{
						if (Forbidden.all) {
							if (a != 0 && a != 5 && a != 7) {
								bap[b][a][p] = true;
							}
						}
						if (Forbidden.revolution) {
							if (a != 0 && a != 4 && a != 6) {
								bap[b][a][p] = true;
							}
						}
						if (Forbidden.upset) {
							if (a > 3) {
								bap[b][a][p] = true;
							}
						}
						if (Player.play[p] == -1) {
							bap[b][a][p] = true;
						}
						if (Table[bx(b)][by(b)].board == -1) {
							bap[b][a][p] = true;
						}
					}

				}
			}
		}

		//同アングルの正否を設定
		int tx, ty, px, py;
		int pret[7][7], t[7][7];
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			for (int prea = 0; prea < 7; prea++) {
				sameangle[p][prea] = false;
			}
		}
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			for (int prea = 0; prea < 7; prea++) {
				for (int a = prea + 1; a < 8; a++) {
					if (sameangle[p][a - 1] == false) {
						sameangle[p][a - 1] = true;
						for (int x = 0; x < 7; x++) {
							for (int y = 0; y < 7; y++) {
								pret[x][y] = 0;
								t[x][y] = 0;
							}
						}
						pret[3][3] = 1;
						t[3][3] = 1;
						for (int fcount = 0; fcount < 4; fcount++) {
							px = 3;
							py = 3;
							tx = 3;
							ty = 3;
							switch (prea) {
							case 0://原型
								px += Player.p[p].fan[fcount].x;
								py += Player.p[p].fan[fcount].y;
								break;
							case 1://90度回転
								px += Player.p[p].fan[fcount].y;
								py += Player.p[p].fan[fcount].x * -1;
								break;
							case 2://180度回転
								px += Player.p[p].fan[fcount].x * -1;
								py += Player.p[p].fan[fcount].y * -1;
								break;
							case 3://270度回転
								px += Player.p[p].fan[fcount].y * -1;
								py += Player.p[p].fan[fcount].x;
								break;
							case 4://上下反転
								px += Player.p[p].fan[fcount].x;
								py += Player.p[p].fan[fcount].y * -1;
								break;
							case 5://上下反転 & 90度回転
								px += Player.p[p].fan[fcount].y * -1;
								py += Player.p[p].fan[fcount].x * -1;
								break;
							case 6://上下反転 & 180度回転
								px += Player.p[p].fan[fcount].x * -1;
								py += Player.p[p].fan[fcount].y;
								break;
							case 7://上下反転 & 270度回転
								px += Player.p[p].fan[fcount].y;
								py += Player.p[p].fan[fcount].x;
								break;
							}
							switch (a) {
							case 0://原型
								tx += Player.p[p].fan[fcount].x;
								ty += Player.p[p].fan[fcount].y;
								break;
							case 1://90度回転
								tx += Player.p[p].fan[fcount].y;
								ty += Player.p[p].fan[fcount].x * -1;
								break;
							case 2://180度回転
								tx += Player.p[p].fan[fcount].x * -1;
								ty += Player.p[p].fan[fcount].y * -1;
								break;
							case 3://270度回転
								tx += Player.p[p].fan[fcount].y * -1;
								ty += Player.p[p].fan[fcount].x;
								break;
							case 4://上下反転
								tx += Player.p[p].fan[fcount].x;
								ty += Player.p[p].fan[fcount].y * -1;
								break;
							case 5://上下反転 & 90度回転
								tx += Player.p[p].fan[fcount].y * -1;
								ty += Player.p[p].fan[fcount].x * -1;
								break;
							case 6://上下反転 & 180度回転
								tx += Player.p[p].fan[fcount].x * -1;
								ty += Player.p[p].fan[fcount].y;
								break;
							case 7://上下反転 & 270度回転
								tx += Player.p[p].fan[fcount].y;
								ty += Player.p[p].fan[fcount].x;
								break;
							}
							pret[px][py] = 1;
							t[tx][ty] = 1;
						}
						for (int x = 0; x < 7; x++) {
							for (int y = 0; y < 7; y++) {
								if (pret[x][y] != t[x][y]) {
									sameangle[p][a - 1] = false;
									break;
								}
							}
							if (sameangle[p][a - 1] == false) { break; }
						}
					}
				}
			}
		}
	}
	void startsort2(){
		resortcount = 0;
		phase = 0;
		restp = PIECECOUNT - Forbidden.rest;
	}
	//盤面に対する余剰ピース数を返します。-1の時は盤面の余剰分を考慮しても絶対に盤面を埋めきれないことを示します。
	int notsetpiece() {
		int nsc = Forbidden.rest;
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			if (ppatcount[p] == 0 && Player.play[p] == 0) {
				nsc--;
				if (nsc < 0) {
					break;
				}
			}
		}
		for (int x = 1; x < TWidth; x++) {
			for (int y = 1; y < THeight; y++) {
				if (Table[x][y].board == 0 && cant[x][y] == 0) {
					//残りピースで絶対に設置できないマスがある時は返り値を-1(やり直し)にします。
					nsc = -1;
				}
			}
		}
		return nsc;
	}
	//盤面の状況を確認し、ピースを設置できないスペースがあるかどうかを確認します。ソート用
	bool Check() {
		bool r = true;
		for (int x = 1; x < TWidth + 1; x++) {
			for (int y = 1; y < THeight + 1; y++) {
				if (Table[x][y].board > 0) {
					if (Table[x][y].board > 100) {
						Table[x][y].check = Table[x][y].board - 100;
					}
					else {
						Table[x][y].check = 100;
					}
				}
				else {
					if (Table[x][y].board == -1) {
						Table[x][y].check = 100;
					}
					else {
						Table[x][y].check = -1;
					}
				}
			}
		}
		for (int x = 1; x < TWidth + 1; x++) {
			for (int y = 1; y < THeight + 1; y++) {
				if (Table[x][y].check == -1) {
					if (Table[x - 1][y].board != 0 || Table[x][y - 1].board != 0 || Table[x + 1][y].board != 0 || Table[x][y + 1].board != 0) {
						Table[x][y].check = 0;
					}
				}
			}
		}
		checkspace = 0;
		for (int x = 1; x < TWidth + 1; x++) {
			for (int y = 1; y < THeight + 1; y++) {
				if (Table[x][y].check == 0) {
					checkspace = 1;
					Table[x][y].check = 100;
					CheckSpace(x + 1, y);
					CheckSpace(x, y + 1);
					CheckSpace(x - 1, y);
					CheckSpace(x, y - 1);
					if (checkspace < (12 - pcount) * 5 && checkspace % 5 != 0) {
						for (int xx = 1; xx < TWidth + 1; xx++) {
							for (int yy = 1; yy < THeight + 1; yy++) {
								if (Table[xx][yy].check < 1 || Table[xx][yy].check == 100) {
									if (Table[xx - 1][yy].board > 0 || Table[xx][yy - 1].board > 0 || Table[xx + 1][yy].board > 0 || Table[xx][yy + 1].board > 0) {
										Table[xx][yy].check = 0;
									}
									else {
										Table[xx][yy].check = -1;
									}
								}
							}
						}
						return false;
					}
				}
				if (checkspace >= (12 - pcount) * 5) {
					break;
				}
			}
			if (checkspace >= (12 - pcount) * 5) {
				break;
			}
		}
		for (int x = 1; x < TWidth + 1; x++) {
			for (int y = 1; y < THeight + 1; y++) {
				if (Table[x][y].check < 1 || Table[x][y].check == 100) {
					if (Table[x - 1][y].board > 0 || Table[x][y - 1].board > 0 || Table[x + 1][y].board > 0 || Table[x][y + 1].board > 0) {
						Table[x][y].check = 0;
					}
					else {
						Table[x][y].check = -1;
					}
				}
			}
		}
		return r;
	}
	//盤面のスペース数を数えます。盤面外だったり空白マスでない場合はそのまま終了します。空白マスの場合は上下左右マスを再帰的に調査します。
	void CheckSpace(int sx, int sy) {
		if (sx < 1 || sx > TWidth || sy < 1 || sy > THeight || Table[sx][sy].check  > 0) {
			return;
		}
		else {
			checkspace++;
		}
		Table[sx][sy].check = 100;
		CheckSpace(sx + 1, sy);
		CheckSpace(sx, sy + 1);
		CheckSpace(sx - 1, sy);
		CheckSpace(sx, sy - 1);
		return;
	}
	//ソート完了後にcanからヒントデータを返します。
	void GetHint(int &p, int &a, int &x, int &y, int hint) {
		p = can[hint].p;
		a = can[hint].a;
		x = bx(can[hint].b);
		y = by(can[hint].b);
	}
	//ピースを盤面から削除し優先度を最後列に回します。ソート用
	void Remove(int p) {
		for (int x = 1; x < TWidth + 1; x++) {
			for (int y = 1; y < THeight + 1; y++) {
				if (Table[x][y].board == p || Table[x][y].board == p + 100) {
					Table[x][y].board = 0;
				}
			}
		}
	}
	//ソートにて予め設置できないパターンをbapに設定します。また盤面マス(bpatcount)、ピース(ppatcount)毎に設置可能パターン数を集計します。
	void SortNotsetPattern() {	
		Check();
		for (int x = 1; x < TWidth + 1; x++) {
			for (int y = 1; y < THeight + 1; y++) {
				if (Table[x][y].board == 0) {
					if (x == 1 || y == 1 || y == THeight || x == TWidth) {
						Table[x][y].check = 0;
					}
					if (Table[x - 1][y].board != 0 || Table[x][y - 1].board != 0 || Table[x + 1][y].board != 0 || Table[x][y + 1].board != 0) {
						Table[x][y].check = 0;
					}
				}
			}
		}
		int tx, ty;//bをテーブルの座標に戻し、かつピース範囲を計算するための変数。
		int ctx, cty;//ピースの中心位置
		//盤面の状況をもとに設置不可パターンを設定(ゲーム開始時点で設置不可なパターンを設定)
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			for (int b = 1; b < TWidth * THeight + 1; b++) {
				for (int a = 0; a < 8; a++) {
					bap[b][a][p] = false;
					{
						if (Forbidden.all) {
							if (a != 0 && a != 5 && a != 7) {
								bap[b][a][p] = true;
							}
						}
						if (Forbidden.revolution) {
							if (a != 0 && a != 4 && a != 6) {
								bap[b][a][p] = true;
							}
						}
						if (Forbidden.upset) {
							if (a > 3) {
								bap[b][a][p] = true;
							}
						}
						if (Player.play[p] == -1) {
							bap[b][a][p] = true;
						}
						if (Table[bx(b)][by(b)].board == -1) {
							bap[b][a][p] = true;
						}
					}

				}
			}
		}
		
		int ap = 1;
		for (int app = 1; app < 10000; app++) {
			allpat[app].b = 0;
			allpat[app].a = 0;
			allpat[app].p = 0;
		}
		for (int b = 1; b < TWidth * THeight + 1; b++) {
			ctx = bx(b);
			cty = by(b);
			//cant,onlypatを並行して初期化
			cant[ctx][cty] = 0;
			onlypat[ctx][cty].b = 0;
			onlypat[ctx][cty].a = 0;
			onlypat[ctx][cty].p = 0;
			for (int p = 1; p < PIECECOUNT + 1; p++) {				
				for (int a = 0; a < 8; a++) {
					if (bap[b][a][p] == false) {						
						if (Player.play[p] == -1 ||( a > 0 && sameangle[p][a - 1]) || Table[ctx][cty].board != 0 || Table[ctx][cty].check > 0) {
							bap[b][a][p] = true;
						}
						else {							
							for (int fcount = 0; fcount < 4; fcount++) {
								tx = ctx;
								ty = cty;
								switch (a) {
								case 0://原型
									tx += Player.p[p].fan[fcount].x;
									ty += Player.p[p].fan[fcount].y;
									break;
								case 1://90度回転
									tx += Player.p[p].fan[fcount].y;
									ty += Player.p[p].fan[fcount].x * -1;
									break;
								case 2://180度回転
									tx += Player.p[p].fan[fcount].x * -1;
									ty += Player.p[p].fan[fcount].y * -1;
									break;
								case 3://270度回転
									tx += Player.p[p].fan[fcount].y * -1;
									ty += Player.p[p].fan[fcount].x;
									break;
								case 4://上下反転
									tx += Player.p[p].fan[fcount].x;
									ty += Player.p[p].fan[fcount].y * -1;
									break;
								case 5://上下反転 & 90度回転
									tx += Player.p[p].fan[fcount].y * -1;
									ty += Player.p[p].fan[fcount].x * -1;
									break;
								case 6://上下反転 & 180度回転
									tx += Player.p[p].fan[fcount].x * -1;
									ty += Player.p[p].fan[fcount].y;
									break;
								case 7://上下反転 & 270度回転
									tx += Player.p[p].fan[fcount].y;
									ty += Player.p[p].fan[fcount].x;
									break;
								}
								if (tx < 1 || tx > TWidth || ty < 1 || ty > THeight) {
									bap[b][a][p] = true;
									break;
								}
								if (Table[tx][ty].board != 0) {
									bap[b][a][p] = true;
									break;
								}
							}
							if (bap[b][a][p] == false) {
								allpat[ap].b = b;
								allpat[ap].a = a;
								allpat[ap].p = p;
								ap++;
							}
							if (Table[ctx][cty].check == -1) {
								//bap[b][a][p] = true;
							}

						}
					}
				}
			}
		}
		//*
		int p;
		for (int app = 1; app < ap; app++) {			
			p = allpat[app].p;
			tx = bx(allpat[app].b);
			ty = by(allpat[app].b);
			cant[tx][ty]++;
			for (int fcount = 0; fcount < 4; fcount++) {
				tx = bx(allpat[app].b);
				ty = by(allpat[app].b);
				switch (allpat[app].a) {
				case 0://原型
					tx += Player.p[p].fan[fcount].x;
					ty += Player.p[p].fan[fcount].y;
					break;
				case 1://90度回転
					tx += Player.p[p].fan[fcount].y;
					ty += Player.p[p].fan[fcount].x * -1;
					break;
				case 2://180度回転
					tx += Player.p[p].fan[fcount].x * -1;
					ty += Player.p[p].fan[fcount].y * -1;
					break;
				case 3://270度回転
					tx += Player.p[p].fan[fcount].y * -1;
					ty += Player.p[p].fan[fcount].x;
					break;
				case 4://上下反転
					tx += Player.p[p].fan[fcount].x;
					ty += Player.p[p].fan[fcount].y * -1;
					break;
				case 5://上下反転 & 90度回転
					tx += Player.p[p].fan[fcount].y * -1;
					ty += Player.p[p].fan[fcount].x * -1;
					break;
				case 6://上下反転 & 180度回転
					tx += Player.p[p].fan[fcount].x * -1;
					ty += Player.p[p].fan[fcount].y;
					break;
				case 7://上下反転 & 270度回転
					tx += Player.p[p].fan[fcount].y;
					ty += Player.p[p].fan[fcount].x;
					break;
				}
				cant[tx][ty]++;
				if (onlypat[tx][ty].b == 0) {
					onlypat[tx][ty].b = allpat[app].b;
					onlypat[tx][ty].a = allpat[app].a;
					onlypat[tx][ty].p = allpat[app].p;
				}
				else {
					onlypat[tx][ty].b = 0;
					onlypat[tx][ty].a = 0;
					onlypat[tx][ty].p = 0;
				}
			}		
		}	//*/	
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			ppatcount[p] = 0;
		}
		
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			for (int b = 1; b < TWidth * THeight + 1; b++) {
				for (int a = 0; a < 8; a++) {
					if (bap[b][a][p] == false /*&& (a == 0 || sameangle[p][a - 1] == false)*/) {
						ppatcount[p]++;						
					}
				}
			}
		}
		int a = 0;
	}
	
private:
	bool bap[TWidth * THeight + 1][8][PIECECOUNT + 1];//[特定の位置]に[特定のアングル]で[特定のピース]が設置できるかどうかを示す配列です。trueの場合設置不可。ステージの初期設定時に決定。
	bool sameangle[PIECECOUNT + 1][7];//回転・反転後もなお同一のアングルであるかどうかを決定します。trueの時はbapにてangleの相違がカウントされません。angleは1～7を対象とし基本は[a - 1]で表記。
	struct candidate {
		short b;//1～60
		short a;//0～7
		short p;//1～12
		short phase;//そのパターンが採用候補となったフェーズ。
		bool adopted;//採用候補となったフェーズでランダムに採用されたかを示します。後のフェーズで失敗しやり直しとなった際に再度ランダム抽選されます。
	};
	candidate can[1000];//各フェーズにて設置可能なパターンを登録する配列です。
	struct BAP {
		short b;
		short a;
		short p;
	};
	BAP allpat[10000];
	BAP onlypat[TWidth + 1][THeight + 1];//その盤面マスを唯一埋めることが出来る設置パターンを記録します。複数可能な場合は0になります。
	//short bpatcount[TWidth * THeight + 1];//各盤面マスごとに設置できるパターン数の総計を集計します。
	short ppatcount[PIECECOUNT + 1];//各ピースごとに設置できるパターン数の総計を集計します。
	short cant[TWidth + 1][THeight + 1];//全設置可能パターンをテーブルに当てはめて、そこで設置不可なマスが存在するかどうかを調べます。
	short resortcount;//ソート中の失敗が10回続いた場合は最初からやり直す。
	int phase;//ソートフェーズ。最初に全ピース数の1/4ずつ埋めていき、残数が1/3を切った段階で全盤面のうち設置可能パターンが最も少ないマスを優先的に設置していく
	int restp;//ピースの残数

};
class PENTA {

public:
	Pentomino penta;
	Sort2 srt;
	Pentomino::pLAYER * pl;//引数名省略のため
	
	PENTA::PENTA() {
		pl = &penta.Player;
		img.title = LoadGraph("./Data/Title.png");
		img.levelselect = LoadGraph("./Data/Levelselect.png");
		img.stageselect = LoadGraph("./Data/Stageselect.png");
		img.lock = LoadGraph("./Data/lock.png");
		img.unlocked= LoadGraph("./Data/unlocked.png");
		img.porse = LoadGraph("./Data/porse.png");
		img.nextp = LoadGraph("./Data/nexting.png");
		img.clearedlevel = LoadGraph("./Data/Lvclear.png");
		img.clearedstage = LoadGraph("./Data/Stgclear.png");
		img.setting = LoadGraph("./Data/Setting.png");
		img.mselect = LoadGraph("./Data/Mslt.png");
		bgm[0] = LoadSoundMem("./Data/BGM・SE/title.mp3");
		
		string music = string("./Data/BGM・SE/bgm");
		for (int b = 1; b < MUSIC + 1; b++) {
			string back = music + to_string(b ) + string(".mp3");
			bgm[b] = LoadSoundMem(back.c_str());			
		}		
		se.ok = LoadSoundMem("./Data/BGM・SE/ok.mp3");
		se.cancel = LoadSoundMem("./Data/BGM・SE/cancel.mp3");
		se.select = LoadSoundMem("./Data/BGM・SE/select.mp3");
		se.set = LoadSoundMem("./Data/BGM・SE/pieceset.mp3");
		se.clear = LoadSoundMem("./Data/BGM・SE/clear.mp3");
		se.button = LoadSoundMem("./Data/BGM・SE/button1.mp3");
		img.porseholizon = MakeGraph(640, 480);
		img.clearboard = MakeGraph(440, 280);
		Font.bproof = CreateFontToHandle("MS ゴシック", 25, 3, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		Font.sproof = CreateFontToHandle("MS ゴシック", 22, 3, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		Font.Level = CreateFontToHandle("Century Gothic", 40, 3, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		Font.Clear = CreateFontToHandle("MS Pゴシック", 40, 3, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		Font.sClear = CreateFontToHandle("MS Pゴシック", 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		char buf[50] = "./Data/Lv";
		char grade[5];
		char buff[50];
		minostyle[0] = LoadGraph("./Data/Mino.png");
		string mino = string("./Data/Mino");
		string mm;
		for (int m = 1; m < 10; m++) {
			mm = mino + to_string(m) + string(".png");
			minostyle[m] = LoadGraph(mm.c_str());
		}
		for (int lv = 1; lv < 8; lv++) {
			strcpy_s(buff, 50, buf);
			_itoa_s(lv, grade, 5, 10);
			strcat_s(buff, 50,grade);
			strcat_s(buff, 50, ".png");
			img.lv[lv] = LoadGraph(buff);
		}
		levelname[1] = "Lento";
		levelname[2] = "Adagio"; 
		levelname[3] = "Andante"; 
		levelname[4] = "Grave"; 
		levelname[5] = "Animato"; 
		levelname[6] = "Allegro"; 
		levelname[7] = "Presto";
		//img.lockedstage = LoadGraph("./Data/lockedstage.png");
		//img.playablestage = LoadGraph("./Data/playablestage.png");
		//img.clearedstage = LoadGraph("./Data/clearedstage.png");
		//img.porse = LoadGraph("./Data/porse.png");
		//img.clear= LoadGraph("./Data/clear.png");
	}
	//DataLoad,DataSaveはDataファイル内に入出力するバージョン
	int DataLoad() {
		int savedata;
		savedata = FileRead_open("./Data/PlayerData.txt");
		if (savedata == -1) {
			return -1;
		}
		int sz = 128;
		char  buff[128];
		FileRead_gets(buff, sz, savedata);
		// ID/name/minostyle/music/musicstyle/recentstage/fproof
		int s = sizeof(buff);
		if (strcmp(buff,"") == 0) {
			FileRead_close(savedata);
			return 1;
		}
		Config.id = atoi(buff);
		if (Config.id == 0) {
			FileRead_close(savedata);
			return 1;
		}
		FileRead_gets(buff, sz, savedata);
		Config.name = string(buff);
		FileRead_gets(buff, sz, savedata);
		Config.minostyle = atoi(buff);
		penta.SetStyle(minostyle[Config.minostyle]);
		FileRead_gets(buff, sz, savedata);
		Config.bgm = (string("true") == string(buff)) ? true : false;
		FileRead_gets(buff, sz, savedata);
		Config.se = (string("true") == string(buff)) ? true : false;
		FileRead_gets(buff, sz, savedata);
		Config.musicstyle = atoi(buff);		
		FileRead_gets(buff, sz, savedata);
		Config.recentstage = atoi(buff);
		FileRead_gets(buff, sz, savedata);
		Config.fproof = (string("true") == string(buff)) ? true : false;
		FileRead_close(savedata);
		return 0;
	}
	void DataSave() {
		FILE *fp;
		fopen_s(&fp, "./Data/PlayerData.txt", "w");
		string save;
		// ID/name/minostyle/bgm/se/musicstyle/recentstage/fproof
		save = to_string(Config.id);
		fputs(save.c_str(), fp);
		fputs("\n", fp);
		save = string(Config.name);
		fputs(save.c_str(), fp);
		fputs("\n", fp);
		save = to_string(Config.minostyle);
		fputs(save.c_str(), fp);
		fputs("\n", fp);
		save = (Config.bgm) ? string("true") : string("false");
		fputs(save.c_str(), fp);
		fputs("\n", fp);
		save = (Config.se) ? string("true") : string("false");
		fputs(save.c_str(), fp);
		fputs("\n", fp);
		save = to_string(Config.musicstyle);
		fputs(save.c_str(), fp);
		fputs("\n", fp);
		save = to_string(Config.recentstage);
		fputs(save.c_str(), fp);
		fputs("\n", fp);
		save = (Config.fproof) ? string("true") : string("false");		
		fputs(save.c_str(),fp);
		fclose(fp);
	}
	//DataBLoad,DataBSaveは実行ファイルのあるディレクトリに構造体ごとバイナリデータとして入出力するバージョン 未実装
	int DataBLoad() {
		FILE *data;	
		fopen_s(&data, "./PlayerData.dat", "rb");
		if (fread_s(&Config.bgm, sizeof(bool), sizeof(bool), 1, data) < 1) {
			fclose(data);
			return -1;
		}
		fread_s(&Config.fproof, sizeof(bool), sizeof(bool), 1, data);
		fread_s(&Config.id, sizeof(int), sizeof(int), 1, data);
		fread_s(&Config.minostyle, sizeof(int), sizeof(int), 1, data);
		fread_s(&Config.musicstyle, sizeof(int), sizeof(int), 1, data);
		fread_s(&Config.name, sizeof(string), sizeof(string), 1, data);
		fread_s(&Config.recentstage, sizeof(int), sizeof(int), 1, data);
		fread_s(&Config.se, sizeof(bool), sizeof(bool), 1, data);

		fclose(data);
		return 0;
	}
	void DataBSave() {
		FILE *data;
		fopen_s(&data, "./PlayerData.dat", "wb");
		fwrite(&Config, sizeof(Config), 8, data);
		fclose(data);
	}
	void HintSave(int stagecount,char * address,char * protoaddress) {
		char buff[256];
		FILE  * savedata;
		fopen_s(&savedata, address, "w");
		int scount = stagecount;
		string data;		
		char * hint;
		char * ctx;
		int protodata = FileRead_open(protoaddress);
		for (int level = 1; level < 8; level++) {
			for (int s = 1; s < 21; s++) {
				FileRead_gets(buff, 256, protodata);
				data = string(strtok_s(buff, "/", &ctx));
				for (int f = 1; f < 6; f++) {
					data += string("/");
					data += string(strtok_s(NULL, "/", &ctx));
				}
				//data += string("/");
				hint = strtok_s(NULL, "/", &ctx);
				if (strcmp(hint, "0") == 0 && Stagedata[level][s].Hint[1].p != 0) {
					data += string("/");
					for (int h = 1; h < 6; h++) {
						if (Stagedata[level][s].Hint[h].p < 10) {
							data += string("0");							
						}
						data += to_string(Stagedata[level][s].Hint[h].p);
						if (Stagedata[level][s].Hint[h].x< 10) {
							data += string("0");
						}
						data += to_string(Stagedata[level][s].Hint[h].x);
						if (Stagedata[level][s].Hint[h].y < 10) {
							data += string("0");
						}
						data += to_string(Stagedata[level][s].Hint[h].y);
						data += string("0");
						data += to_string(Stagedata[level][s].Hint[h].angle);
						if (h < 5) {
							data += string("-");
						}
					}
				}
				else {
					data += string("/");
					data += string(hint);
				}
				data += string("/");
				data += string(strtok_s(NULL, "/", &ctx));				
				data += string("\n");
				fputs(data.c_str(), savedata);
				if (FileRead_eof(protodata) != 0) {
					break;
				}
			}
			if (FileRead_eof(protodata) != 0) {
				break;
			}
		}
		FileRead_close(protodata);
		fclose(savedata);
	}
	void LoadStageData(int &lstage, char * address) {
		int stagedata;
		stagedata = FileRead_open(address);
		if (stagedata == -1) {
			return;
		}
		char  buff[256], notuse[256], preset[256], hint[256], evil[256];
		char * ctx;
		char * boole;

		// レベル/ステージ/反転禁止/回転禁止/使用不可/設置済み(ppxxyyaa)/ヒント1～5(ppxxyyaa)/設置不可
		if (FileRead_eof(stagedata) != 0) {
			FileRead_close(stagedata);
			return;
		}
		int level, stage;
		lstage = 0;
		while (FileRead_eof(stagedata) == 0) {
			FileRead_gets(buff, 256, stagedata);
			//boole = strtok_s(buff, "/", &ctx);
			level = atoi(strtok_s(buff, "/", &ctx));
			stage = atoi(strtok_s(NULL, "/", &ctx));
			boole = strtok_s(NULL, "/", &ctx);
			Stagedata[level][stage].notupset = (strcmp(boole, "False") == 0) ? false : true;
			Stagedata[level][stage].notturn = (strcmp(strtok_s(NULL, "/", &ctx), "False") == 0) ? false : true;
			strcpy_s(notuse, strtok_s(NULL, "/", &ctx));//分割した文字列を収容し別途分割する
			strcpy_s(preset, strtok_s(NULL, "/", &ctx));//分割した文字列を収容し別途分割する
			strcpy_s(hint, strtok_s(NULL, "/", &ctx));//分割した文字列を収容し別途分割する
			strcpy_s(evil, strtok_s(NULL, "/", &ctx));//分割した文字列を収容し別途分割する
			if (strcmp(notuse, "0") != 0) {
				string bnuse(notuse);
				string nuse;
				unsigned int cf = 0;
				unsigned int ce = 0;
				while (ce < bnuse.size()) {
					ce = bnuse.find(",", cf);
					if (ce == -1) {
						int n = atoi(notuse);
						Stagedata[level][stage].notusep[n] = true;
						ce = 100;
					}
					else {
						nuse = bnuse.substr(cf, ce - cf);
						Stagedata[level][stage].notusep[atoi(nuse.c_str())] = true;
					}

					cf = ce + 1;
				}
			}
			if (strcmp(preset, "0") != 0) {
				string bpset(preset);//ppxxyyaa
				string pset;
				string ps;
				int p, x, y, a;
				unsigned int cf, ce;
				cf = 0;
				ce = 0;
				while (ce < bpset.size()) {
					ce = bpset.find(",", cf);
					pset = bpset.substr(cf, ce - cf);
					ps = pset.substr(0, 2);
					p = atoi(ps.c_str());
					ps = pset.substr(2, 2);
					x = atoi(ps.c_str());
					ps = pset.substr(4, 2);
					y = atoi(ps.c_str());
					ps = pset.substr(6, 2);
					a = atoi(ps.c_str());
					Stagedata[level][stage].Preset[p].x = x;
					Stagedata[level][stage].Preset[p].y = y;
					Stagedata[level][stage].Preset[p].angle = a;
					cf = ce + 1;
				}
			}
			if (strcmp(hint, "0") != 0) {
				string bufhint(hint);//ppxxyyaa
				string phint;
				string ps;
				int p, x, y, a;
				int h = 0;
				while (h < 5) {
					phint = bufhint.substr(h * 9, 8);
					h++;
					ps = phint.substr(0, 2);
					p = atoi(ps.c_str());
					ps = phint.substr(2, 2);
					x = atoi(ps.c_str());
					ps = phint.substr(4, 2);
					y = atoi(ps.c_str());
					ps = phint.substr(6, 2);
					a = atoi(ps.c_str());
					Stagedata[level][stage].Hint[h].p = p;
					Stagedata[level][stage].Hint[h].x = x;
					Stagedata[level][stage].Hint[h].y = y;
					Stagedata[level][stage].Hint[h].angle = a;
				}
			}
			if (strcmp(evil, "0") != 0) {
				string bevil(evil);
				string evilcell;//xxyy,x1y1～x2y2
				string ev;
				unsigned int cf, ce;
				cf = 0;
				ce = 0;
				while (ce < bevil.size()) {
					ce = bevil.find(",", cf);
					evilcell = bevil.substr(cf, ce - cf);
					if (evilcell.find("～") == -1) {
						//xxyy
						int x, y;
						ev = evilcell.substr(0, 2);
						x = atoi(ev.c_str());
						ev = evilcell.substr(2, 2);
						y = atoi(ev.c_str());
						Stagedata[level][stage].evil[x][y] = true;
					}
					else {
						//x1y1～x2y2
						int x1, y1, x2, y2;
						ev = evilcell.substr(0, 2);
						x1 = atoi(ev.c_str());
						ev = evilcell.substr(2, 2);
						y1 = atoi(ev.c_str());
						ev = evilcell.substr(6, 2);
						x2 = atoi(ev.c_str());
						ev = evilcell.substr(8, 2);
						y2 = atoi(ev.c_str());
						for (int ex = x1; ex < x2 + 1; ex++) {
							for (int ey = y1; ey < y2 + 1; ey++) {
								Stagedata[level][stage].evil[ex][ey] = true;
							}
						}
					}
					cf = ce + 1;
				}
			}
			lstage++;
		}
		FileRead_close(stagedata);
	}
	//カーソルの座標からゲーム画面内のポジション別に番号を返します。特別な場所でない場合は0が帰ります。
	int GetMousePosition() {
		int ps = 0;
		int x = Mouse.x;
		int y = Mouse.y;
		if (Mouse.x > 490 && Mouse.x < 610) {
			if (Mouse.y > 20 && Mouse.y < 70) {
				ps = 6;
			}
			if (Mouse.y > 90 && Mouse.y < 140) {
				ps = 7;
			}
			if (Mouse.y > 160 && Mouse.y < 210) {
				ps = 8;
			}
			if (Mouse.y > 230 && Mouse.y < 280) {
				ps = 9;
			}
		}
		if (penta.Player.choose > 0) {//選択状態にあるピースがある場合
			//中心マスの座標を計算
			int x = pl->cx + pl->p[pl->choose].fan[4].x;
			int y = pl->cy + pl->p[pl->choose].fan[4].y;
			int fx, fy;
			if (x < Mouse.x && x + 40 > Mouse.x && y < Mouse.y && y + 40 > Mouse.y) {
				ps = 3;
			}
			else {
				for (int f = 0; f < 4; f++) {
					fx = x + pl->p[pl->choose].fan[f].x * 40;
					fy = y + pl->p[pl->choose].fan[f].y * 40;
					if (fx < Mouse.x && fx + 40 > Mouse.x && fy < Mouse.y && fy + 40 > Mouse.y) {
						ps = 3;
					}
				}
			}
			
		}
		else {
			if (x > 20 && x < 460 && y > 20 && y < 300) {
				//盤面内
				ps = 4;
			}			
			//if (Mouse.x > 590 && Mouse.x < 610 && Mouse.y > 365 && Mouse.y < 425) {
			if (TriangleRange(588, 363, 588, 432, 617, 395)) {
				ps = 10;//nextボタン
			}
			if (x > 130 && x < 430 && y > 360 && y < 430) {
				//待ちピース枠内
				ps = 2;
			}
			if (x > 430 && x < 580 && y > 320 && y < 470) {
				//メインピース枠内
				ps = 1;
			}			
		}		
		int rx, ry, hx, hy;
		penta.GetButton(2, &rx, &ry);
		penta.GetButton(3, &hx, &hy);
		if (hx == 0) {
			hx = rx;
			hy = ry;
		}
		if (rx == 0) {
			penta.GetButton(1, &rx, &ry);
		}
		if (Mouse.x > rx && Mouse.x < hx + 50 && Mouse.y > ry && Mouse.y < hy + 50) {
			ps = 5;
		}
		return ps;
	}
	void Game() {		
		if (penta.AllPieceSet() == false && penta.AllTableSet() == false) {
			//ゲームプレイ中
			int pos;//マウスポジション。1.メインピース枠内、2.待ちピース枠内 3.選択状態にあるピース枠内 4.盤面 5.回転・反転ボタン 6.1手戻るボタン 7.最初からボタン 8.Porseボタン 9.ヒントボタン 10.Nextボタン -1.画面外
			pos = GetMousePosition();
			int main;
			main = 100;
			int fp;
			fp = 0;
			int rank;			
			bool next = false;//DisplayBoardの後にnextボタンのエフェクトを表示するための変数
			switch (Mouse.click) {
			case 0://クリックされていない。選択状態にあるピースの有無とピースの場所によって処理を行う。
				break;
			case 1://シングルクリック。押された場所がボタンならそれに応じた処理を行う。固定化されていないピースならそのピースを選択状態にする。				
				switch (pos) {
				case 1://メインピース枠内
					fp = pl->root;
					pl->choose = fp;
					pl->cx = Mouse.x - pl->p[pl->choose].fan[4].x - 20;
					pl->cy = Mouse.y - pl->p[pl->choose].fan[4].y - 20;
					pl->mcx = Mouse.x - pl->cx;
					pl->mcy = Mouse.y - pl->cy;
					pl->pp[pl->np[fp]] = 0;
					pl->root = pl->np[fp];
					Mouse.click = 3;
					Sound(se.select);
					break;
				case 2://待ちピース枠
					if (pl->choose > 0) {
						penta.PlayerRemove(pl->choose);
					}
					else {
						if (Mousebefore.click != 3) {
							rank = 0;							
							if (Mouse.x > 160 && Mouse.x < 210 && Mouse.y > 360 && Mouse.y < 410) {
								rank = 5;
							}
							if (Mouse.x > 230 && Mouse.x < 280 && Mouse.y > 360 && Mouse.y < 410) {
								rank = 4;
							}
							if (Mouse.x > 300 && Mouse.x < 350 && Mouse.y > 360 && Mouse.y < 410) {
								rank = 3;
							}
							if (Mouse.x > 370 && Mouse.x < 420 && Mouse.y > 360 && Mouse.y < 410) {
								rank = 2;
							}
							if (rank > 0) {
								int fp = pl->root;
								int pcount = 1;
								while (pcount != rank && pcount < 6) {
									fp = pl->np[fp];
									pcount++;
								}
								if (pcount < 6) {
									pl->choose = fp;
									pl->cx = Mouse.x - pl->p[pl->choose].fan[4].x - 20;
									pl->cy = Mouse.y - pl->p[pl->choose].fan[4].y - 20;
									pl->mcx = Mouse.x - pl->cx;
									pl->mcy = Mouse.y - pl->cy;
									pl->np[pl->pp[fp]] = pl->np[fp];
									if (pl->np[fp] < PIECECOUNT + 1) {
										pl->pp[pl->np[fp]] = pl->pp[fp];
									}
									Mouse.click = 3;
									Sound(se.select);
								}
							}
						}
					}
					break;
				case 3://選択状態にあるピース
					if (Mouse.click != 3 && Mousebefore.click == 3) {
						//一旦選択状態を解除しカーソル位置を再度確認する。
						int choose = pl->choose;
						pl->choose = 0;
						pos = GetMousePosition();
						switch (pos) {
						case 1://選択状態にあるピースを再度メインピース枠内に戻す。
							Mouse.click = 0;
							pl->pp[pl->root] = choose;
							pl->pp[choose] = 0;
							pl->np[choose] = pl->root;
							pl->root = choose;
							Sound(se.select);
							break;
						case 2:
							pl->choose = choose;
							break;
						case 4:
							//盤面にドロップされたとき設置可能な場合は設置し、設置不可能な場合は選択状態を続ける
							pl->mcx = Mouse.x - pl->cx;
							pl->mcy = Mouse.y - pl->cy;
							if (pl->ablex == 0) {
								pl->choose = choose;
							}
							else {
								pl->set[choose].x = pl->ablex;
								pl->set[choose].y = pl->abley;
								pl->played++;
								pl->play[choose] = pl->played;
								//pentaのTableに設置した情報を登録する。
								penta.PlayerSet(choose);
								Sound(se.set);
							}
							break;
						default:
							//それ以外の場合は選択状態を続ける。
							pl->choose = choose;
							break;
						}
					}
					break;
				case 4://盤面
					if (Mousebefore.click != 3) {
						int bcho = pl->choose;
						penta.SearchBoard(Mouse.x, Mouse.y);
						if (bcho != pl->choose) {
							Sound(se.select);
						}
					}
					break;
				case 5://各種コマンドボタン
					if (Mousebefore.click != 3) {
						int bx;
						int by;
						int b;
						penta.GetButton(2, &bx, &by);
						if (Mouse.x > bx && Mouse.x < bx + 50 && by != -1) {
							//90度回転ボタン
							b = 1;
						}
						else {
							penta.GetButton(3, &bx, &by);
							if (Mouse.x > bx && Mouse.x < bx + 50 && by != -1) {
								//左右反転ボタン
								b = 3;
							}
							else {
								penta.GetButton(1, &bx, &by);
								if (Mouse.x > bx && Mouse.x < bx + 50 && by != -1) {
									//上下反転ボタン
									b = 2;
								}
								else
								{
									b = 0;
								}
							}
						}
						if (b > 0) {
							int p = 0;
							if (pl->choose > 0) {
								p = pl->choose;
							}
							else {
								p = pl->root;
							}
							if (p > 0 && p < 13) {
								if (penta.PlayerOperate(b, p) == 0) {									
									Sound(se.select);
								}
								Mouse.click = 0;
							}
							
						}
					}
					break;
				case 6://1手戻るボタン
					penta.PlayerUndo();
					Sound(se.cancel);
					break;
				case 7://最初からボタン
					if (Config.fproof) {
						Gamemode = 7;
						
						penta.DisplayBoard();//盤面の状況を表示
						 GetDrawScreenGraph(0, 0, 640, 480, img.porseholizon);
					}
					else {
						Gamemode = 3;						
					}
					Sound(se.cancel);
					break;
				case 8://Porseボタン
					Gamemode = 4;
					penta.DisplayBoard();//盤面の状況を表示
					GetDrawScreenGraph(0, 0, 640, 480, img.porseholizon);
					Sound(se.button);
					break;
				case 9://ヒントボタン
					penta.PlayerHint();	
					Sound(se.button);
					break;
				case 10://nextボタン	
					{
					if (penta.PlayerRemove(0) == 0) {
						Sound(se.set);
						next = true;
					}
					else {
						//強制初期化
						Gamemode = -1;
						Modechange = 120;
					}
					break;
					}
				}
				break;
			case 2://ダブルクリック。待ちピース枠に無いピースならそのピースを取り除き待ちピース枠に戻す(待ちピースの最後尾に回す）。固定化されたピースは対象外。
				if (pl->choose > 0 && pos == 3) {
					penta.PlayerRemove(pl->choose);
					Sound(se.set);
				}
				if (pos == 4) {
					penta.SearchBoard(Mouse.x, Mouse.y);
					if (pl->choose > 0) {
						penta.PlayerRemove(pl->choose);
					}			
				}
				break;
			case 3://ドラッグ。選択状態ならばその対象のピースをカーソルの位置に合わせて移動させる。
				if (penta.Player.choose > 0) {
					pl->cx = Mouse.x - pl->mcx;
					pl->cy = Mouse.y - pl->mcy;
					if (Mouse.x < 2) {
						pl->cx = 2;
					}
					if (Mouse.y < 2) {
						pl->cy = 2;
					}
					if (pl->cx > 638) {
						pl->cx = 638 - pl->p[pl->choose].width;
					}
					if (pl->cy > 478) {
						pl->cy = 478 - pl->p[pl->choose].height;
					}
				}
				if (Mouse.x > 40 && Mouse.x < 440 && Mouse.y > 40 && Mouse.y < 280) {
					if (pl->cx > 30 && pl->cx+ pl->p[pl->choose].width < 450  && pl->cy > 30 && pl->cy + pl->p[pl->choose].height < 290) {
						//選択状態のピースが盤面内に移動したとき、設置可能な場所があればその部分の左上座標を登録する。					
						penta.AbleSet();
					}
				}
				else {
					pl->ablex = 0;
					pl->abley = 0;
				}
				break;
			case 4://クリックしたまま動かない。その場所が待ちピース枠内のピースならばそのピースを選択状態にする。
				switch (pos) {
				case 1://メインピース枠内
					fp = pl->root;
					pl->choose = fp;
					pl->cx = Mouse.x - pl->p[pl->choose].fan[4].x - 20;
					pl->cy = Mouse.y - pl->p[pl->choose].fan[4].y - 20;
					pl->mcx = Mouse.x - pl->cx;
					pl->mcy = Mouse.y - pl->cy;
					if (pl->np[fp] < PIECECOUNT + 1) {
						pl->pp[pl->np[fp]] = 0;
					}				
					pl->root = pl->np[fp];
					Mouse.click = 3;
					Sound(se.select);
					break;
				case 2://待ちピース枠
					if (pl->choose > 0) {
						penta.PlayerRemove(pl->choose); 
						Sound(se.select);
					}
					else {
						if (Mousebefore.click != 3) {
							rank = 0;							
							if (Mouse.x > 160 && Mouse.x < 210 && Mouse.y > 360 && Mouse.y < 410) {
								rank = 5;
							}
							if (Mouse.x > 230 && Mouse.x < 280 && Mouse.y > 360 && Mouse.y < 410) {
								rank = 4;
							}
							if (Mouse.x > 300 && Mouse.x < 350 && Mouse.y > 360 && Mouse.y < 410) {
								rank = 3;
							}
							if (Mouse.x > 370 && Mouse.x < 420 && Mouse.y > 360 && Mouse.y < 410) {
								rank = 2;
							}
							if (rank > 0) {
								int fp = pl->root;
								int pcount = 1;
								while (pcount != rank && pcount < 6) {
									fp = pl->np[fp];
									pcount++;
								}
								if (pcount < 6) {
									pl->choose = fp;
									pl->cx = Mouse.x - pl->p[pl->choose].fan[4].x - 20;
									pl->cy = Mouse.y - pl->p[pl->choose].fan[4].y - 20;
									pl->mcx = Mouse.x - pl->cx;
									pl->mcy = Mouse.y - pl->cy;
									pl->np[pl->pp[fp]] = pl->np[fp];
									if (pl->np[fp] < PIECECOUNT + 1) {
										pl->pp[pl->np[fp]] = pl->pp[fp];
									}
									Mouse.click = 3;
									Sound(se.select);
								}
							}
						}
					}
					break;
				case 3://選択状態にあるピース
					pl->mcx = Mouse.x - pl->cx;
					pl->mcy = Mouse.y - pl->cy;
					break;
				case 4://盤面
					if (Mousebefore.click != 3) {
						penta.SearchBoard(Mouse.x, Mouse.y);
					}
					break;
				case 5://各種コマンドボタン
					if (Mousebefore.click != 3) {
						int bx;
						int by;
						int b;
						penta.GetButton(2, &bx, &by);
						if (Mouse.x > bx && Mouse.x < bx + 50 && by != -1) {
							//90度回転ボタン
							b = 1;
						}
						else {
							penta.GetButton(3, &bx, &by);
							if (Mouse.x > bx && Mouse.x < bx + 50 && by != -1) {
								//左右反転ボタン
								b = 3;
							}
							else {
								penta.GetButton(1, &bx, &by);
								if (Mouse.x > bx && Mouse.x < bx + 50 && by != -1) {
									//上下反転ボタン
									b = 2;
								}
								else
								{
									b = 0;
								}
							}
						}
						if (b > 0) {
							int p = 0;
							if (pl->choose > 0) {
								p = pl->choose;
							}
							else {
								p = pl->root;
							}
							if (p > 0 && p < 13) {
								if (penta.PlayerOperate(b, p) == 0) {
									Sound(se.select);
								}
								Mouse.click = 0;
							}
						}
					}
					break;
				/*case 6://1手戻るボタン
					//penta.PlayerUndo();
					break;
				case 7://最初からボタン
					break;
				case 8://Porseボタン
					//Gamemode = 4;
					//penta.DisplayBoard(Config.righty);//盤面の状況を表示
					//GetDrawScreenGraph(0, 0, 640, 480, img.porseholizon);
					break;
				case 9://ヒントボタン
					break;
				case 10:
					next = true;
					break;*/
				}
				break;
			}
			if (penta.DisplayBoard() == -1) {//盤面の状況を表示
				Gamemode = -1;
			}
			if (next) {
				DrawGraph(590, 365, img.nextp, true);
			}
			if (pl->choose != 0) {
				//DrawFormatString(100, 90, GetColor(0, 0, 0), "angle = %d", pl->p[pl->choose].angle);
				//DrawFormatString(100, 100, GetColor(0, 0, 0), "p = %d", pl->choose); //デバッグ用
			}
		    //DrawFormatString(100, 100, GetColor(0, 0, 0), "pos = %d", pos);
			//DrawFormatString(100, 90, GetColor(0, 0, 0), "choose = %d", pl->choose);
		}
		else {			
			//ゲームクリア
			pl->choose = 0;
			penta.DisplayBoard();
			if (Modechange == 0) {
				GetDrawScreenGraph(20, 20, 460, 300, img.clearboard);
				Gamemode = 5;
				Modechange = 120;
				Sound(se.clear);				
			}
			
		}		
		if (CheckHitKey(KEY_INPUT_LALT) == 1) {
			//Gamemode = 0;//デバッグ用
		}
	}
	//レベル名 - ステージ番号が表示されるラベルのfont色とage色を返します。
	void GetStageLavel(int &age,int &font) {
		switch (level) {
		case 1:
			age = GetColor(150, 0, 0);
			font = GetColor(250, 50, 50);
			break;
		case 2:
			age = GetColor(200, 150, 0);
			font = GetColor(250, 150, 50);
			break;
		case 3:
			age = GetColor(150, 150, 0);
			font = GetColor(250, 250, 50);
			break;
		case 4:
			age = GetColor(0, 150, 0);
			font = GetColor(50, 250, 50);
			break;
		case 5:
			age = GetColor(0, 150, 150);
			font = GetColor(50, 50, 250);
			break;
		case 6:
			age = GetColor(0, 0, 150);
			font = GetColor(50, 50, 250);
			break;
		case 7:
			age = GetColor(150, 0, 150);
			font = GetColor(250, 50, 250);
			break;
		}
	}
	void StageSelect() {
		if (Mouse.wheel < 0) {
			Mouse.wheel = 0;
		}
		if (Mouse.wheel > 340) {
			Mouse.wheel = 340;
		}
		DrawRectGraph(0, 0, 0, Mouse.wheel, 640, 480, img.stageselect, false);
		int age = 0;
		int font = 0;
		GetStageLavel(age, font);		
		DrawStringToHandle(400 - sizeof(levelname[level]) * 2, 15 - Mouse.wheel, levelname[level],font, Font.Level,age);
		int x = Mouse.x;
		int y = Mouse.y + Mouse.wheel;
		int st = 0;//プレイヤーが選択したステージ
		int stt = 1;//最もレベルと番号の高いステージまではunlock状態とし、それ以上はlock状態とする。
		bool un;//そのステージが解除済みで挑戦できるかどうかを示す。trueの時ステージ番号が表示され、かつプレイヤー操作でプレイできる
		for (int sy = 110; sy < 711; sy += 150) {
			for (int sx = 50; sx < 501; sx += 150) {
				DrawBox(sx, sy - Mouse.wheel, sx + 100, sy + 100 - Mouse.wheel, GetColor(0, 162, 232), true);								
				if (level <= Config.recentstage / 100 - 1 || Config.recentstage % 100 > stt) {					
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
					DrawGraph(sx + 9, sy + 7 - Mouse.wheel, img.clearedstage, true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 150);
					un = true;
				}
				else {
					//ロック中のステージにはimg.lockを表示
					if (Config.recentstage % 100 < stt) {
						DrawGraph(sx + 25, sy + 25 - Mouse.wheel, img.lock, true);
						un = false;
					}
					else {
						un = true;
						
					}
				}		
				if (un) {
					DrawFormatStringToHandle(sx + 35 - ((stt < 10) ? 5 : 10), sy + 25 - Mouse.wheel, GetColor(0, 0, 0), Font.Clear, "%d", stt);
					if (Mouse.x > sx && Mouse.x < sx + 100 && Mouse.y + Mouse.wheel > sy && Mouse.y + Mouse.wheel < sy + 100) {
						st = stt;
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
						DrawBox(sx - 5 , sy - 5  - Mouse.wheel, sx + 95, sy + 95 - Mouse.wheel, GetColor(0, 0, 0), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 150);
					}
				}
				stt++;
			}
		}
		if (st > 0 && Mouse.click == 1) {
			stage = st;
			Gamemode = 3;
			Modechange = 120;
		}
		double daen = (double)(pow(x - 73, 2.0) / pow(53, 2.0)) + (double)(pow(y - 36, 2.0) / pow(26, 2.0)) - 1;
		if (daen  < 0 && Mouse.click) {//終了			
			Gamemode = 1;			
			Modechange = 120;
		}
	}
	void LevelSelect() {
		if (Mouse.wheel < 0) {
			Mouse.wheel = 0;
		}
		if (Mouse.wheel > 520) {
			Mouse.wheel = 520;
		}
		Mouse.wheel = 0;//Grave実装後に削除
		DrawRectGraph(0, 0, 0, Mouse.wheel, 640, 450, img.levelselect, false); //Grave実装後は450→480に修正
		
		int x = Mouse.x;
		int y = Mouse.y + Mouse.wheel; 
		int lv = 0;
		for (int ly = 110; ly < 440; ly += 120) {//Grave実装後は440→840に修正
			if ((ly - 110) / 120 > Config.recentstage / 100 - 1) {
				DrawGraph(300, ly + 20 - Mouse.wheel, img.lock, true);
			}
			else {
				if (Mouse.x > 170 && Mouse.x < 475 && Mouse.y + Mouse.wheel > ly && Mouse.y + Mouse.wheel < ly + 70 && Mouse.click != 4) {
					DrawGraph(170, ly - Mouse.wheel, img.lv[(ly - 110) / 120 + 1], true);
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
					lv = (ly - 110) / 120 + 1;
					DrawBox(170, ly - Mouse.wheel, 475, ly - Mouse.wheel + 70, GetColor(0, 0, 0), true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
				}
				else {
					DrawGraph(170, ly - Mouse.wheel, img.lv[(ly - 110) / 120 + 1], true);
				}
				if ((ly - 10) / 120 < Config.recentstage / 100 - 1) {
					DrawGraph(165, ly - Mouse.wheel - 5, img.clearedlevel, true);
				}
			}
		}
		if (lv > 0 && Mouse.click == 1) {
			level = lv;
			Gamemode = 2;
		}
		double daen = (double)(pow(x - 73, 2.0) / pow(53, 2.0)) + (double)(pow(y - 36, 2.0) / pow(26, 2.0)) - 1;
		if (daen  < 0 && Mouse.click) {//終了			
			Gamemode = 0;
		}
	}
	void Setting() {
		DrawGraph(0, 0, img.setting, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		if (Config.bgm) {
			DrawBox(235, 80, 295, 105, GetColor(250, 0, 0), true);
			if (Mouse.x > 390 && Mouse.y > 80 && Mouse.x < 465 && Mouse.y < 105) {
				DrawBox(390, 80, 465, 105, GetColor(0, 0, 250), true);
				if (Mouse.click == 1) {
					Config.bgm = false;
					StopSoundMem(bgm[0]);
					Sound(se.select);
				}
			}
		}
		else {
			DrawBox(390, 80, 465, 105, GetColor(250, 0, 0), true);
			if (Mouse.x > 235 && Mouse.y > 80 && Mouse.x < 295 && Mouse.y < 105) {
				DrawBox(235, 80, 295, 105, GetColor(0, 0, 250), true);
				if (Mouse.click == 1) {
					Config.bgm = true;
					Sound(bgm[0]);
					Sound(se.select);
				}
			}
			
		}
		if (Config.se) {
			DrawBox(235, 140, 295, 165, GetColor(250, 0, 0), true);
			if (Mouse.x > 390 && Mouse.y > 140 && Mouse.x < 465 && Mouse.y < 165) {
				DrawBox(390, 140, 465, 165, GetColor(0, 0, 250), true);
				if (Mouse.click == 1) {
					Config.se = false;
				}
			}
		}
		else {
			DrawBox(390, 140, 465, 165, GetColor(250, 0, 0), true);
			if (Mouse.x > 235 && Mouse.y > 140 && Mouse.x < 295 && Mouse.y < 165) {
				DrawBox(235, 140, 295, 165, GetColor(0, 0, 250), true);
				if (Mouse.click == 1) {					
					Config.se = true;
					Sound(se.select);
				}
			}

		}
		if (Config.recentstage > 200) {
			DrawExtendGraph(310, 210, 370, 270, minostyle[Config.minostyle], true);
			if (Mouse.x > 310 && Mouse.y > 210 && Mouse.x < 370 && Mouse.y < 270 && Mouse.click == 1) {
				Config.minostyle++;
				Sound(se.select);
				Mouse.click = 3;
				int limit;
				switch ((int)(Config.recentstage / 100)) {
				case 1://0				
					limit = 0;
					break;
				case 2://1～3
					limit = 3;
					break;
				case 3://4～5
					limit = 4;//Grave実装後はlimit = 5;に変更
					break;
				case 4://6
					limit = 4;//Grave実装後はlimit = 6;に変更
					break;
				case 5://7
					limit = 7;
					break;
				case 6://8
					limit = 8;
					break;
				case 7://9
					limit = 9;
					break;
				}
				if (Config.minostyle > limit || Config.minostyle == 0) {
					Config.minostyle = 0;
					penta.SetStyle(0);
				}
				else {
					penta.SetStyle(minostyle[Config.minostyle]);
				}
			}
		}
		else {
			DrawBox(110, 208, 375, 275, GetColor(0, 0, 0), true);
		}
		if (Config.recentstage > 300) {			
			if (TriangleRange(535, 305, 535, 330 ,562, 316)){
				if (Mouse.click == 1) {
					Config.musicstyle++;
					Sound(se.select);
					Mouse.click = 3;
					if (Config.musicstyle == 11) {
						Config.musicstyle = 0;
					}
					if ((Config.recentstage < 600 && Config.musicstyle > 4) || bgm[Config.musicstyle] < 0 || Config.musicstyle > 7) {
						Config.musicstyle = 10;
					}
					if (Config.musicstyle > 0 && Config.musicstyle < 8) {
						Sound(Config.musicstyle);
					}
					else {
						Sound(0);
					}
				}
				else {
					DrawGraph(535, 305, img.mselect, true);
				}
			}		
			if (TriangleRange(294, 306, 266, 317, 294, 330 )) {
				if (Mouse.click == 1) {
					Config.musicstyle--;
					Sound(se.select);
					Mouse.click = 3;
					if (Config.musicstyle == -1) {
						Config.musicstyle = 10;
					}
					if (Config.musicstyle == 9) {
						if (Config.recentstage < 600 || bgm[5] < 0) {
							Config.musicstyle = 4;
						}
						else {
							Config.musicstyle = 7;
						}
					}
					if (Config.musicstyle > 0 && Config.musicstyle < 8) {
						Sound(Config.musicstyle);
					}
					else {
						Sound(0);
					}
				}
				else {
					DrawTurnGraph(266, 305, img.mselect, true);
				}

			}
			string bgmlavel;
			switch (Config.musicstyle) {
			case 0:
				bgmlavel = string("デフォルト");
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				bgmlavel = string("BGM") + to_string(Config.musicstyle);
				break;
			case 10:
				bgmlavel = string("ランダム");
			}
			int fsize;
			GetFontStateToHandle(NULL, &fsize, NULL, Font.sClear);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 150);
			DrawStringToHandle(415 - bgmlavel.size() * fsize / 4, 305, bgmlavel.c_str(), GetColor(0, 0, 0), Font.sClear);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		}
		else {
			DrawBox(110, 300, 570, 340, GetColor(0, 0, 0), true);
		}
		if (Mouse.x > 225 && Mouse.y > 395 && Mouse.x < 415 && Mouse.y < 425) {			
			DrawBox(225, 395, 415, 425, GetColor(100, 0, 100), true);
			if (Mouse.click == 1 && Modechange == 0) {
				Gamemode = 0;
				Modechange = 120;
			}			
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 150);
	}
	void NewiInfo() {
		switch (newinfo) {
		case 0://0.チュートリアル(設置不可マス、設置済みピース、使用不可ピースの説明,各種ボタンの説明
			break;
		case 1://1.Lentoクリア&ピース柄の選択が可能に 
			break;
		case 2://2.Adagioクリア&BGMの形式の選択が可能に 
			break;
		case 3://3.Andanteクリア&新しい柄の追加 
			break;
		case 4://4.Graveクリア&新しい柄の追加
			break;
		case 5://5.Animatoクリア&新しいBGMの追加と選択可
			break;
		case 6://6.Allegroクリア&新しい柄の追加
			break;
		case 7://7.Prestoクリア&広告機能の停止
			break;
		case 8://8.回転禁止・反転禁止の説明
			break;
		case 9://9.Borderの説明 //未定
			break;
		case 10://10.盤面上下ボタンの説明 //未定
			break;
		}
	}
	void Title() {
		int flame = 0;
		int r = 0;
		int beforef;
		int premode;
		int nextmode;
		double daen = 0;
		SetBackgroundColor(255, 255, 255);
		Modechange = 0;
		Gamemode = -1;
		SetDrawScreen(DX_SCREEN_BACK);		
		switch (DataLoad()) {
			case -1://ファイルが見つからない→終了
				DrawString(100, 100, "ファイルが見つかりません", GetColor(255, 255, 255));
				r = -1;
				break;
			case 0://ファイルがあり、セーブデータもある。
				Modechange = 120;
				nextmode = 0;
				break;
			case 1://ファイルがあるがセーブデータがない→新規作成
				Config.id = GetRand(1000000);
				Config.minostyle = 0;
				Config.bgm = true;
				Config.se = true;
				Config.name = string("noname");
				Config.musicstyle = 0;
				Config.recentstage = 0;
				Config.fproof = true;
				Modechange = 120;
				nextmode = 0;
				break;
		}
		{
			int lstage;
			LoadStageData(lstage, "./data/Stagedata.txt");
		}
		Mouse.clickcount = 0;
		Mouse.click = 3; 
		Mouse.clicklog = 1;		
		while (ProcessMessage() == 0  && r == 0) {
			flame = 1;
			beforef = GetNowCount();			
			while (ClearDrawScreen() == 0 && flame < 31 && r == 0) {//fps 30
				UpdateMouseCondition();
				GetMouseCondition();
				premode = Gamemode;				
				switch (Gamemode) {
				case -1://Init
					DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), true);
					break;
				case 0://Title
					DrawGraph(0, 0, img.title, true);
					if (Mouse.click == 1 && Modechange == 0) {
						if (Mouse.x > 187 && Mouse.x < 423) {
							if (Mouse.y > 177 && Mouse.y < 241) {//つづきから
								Modechange = 120;								
								nextmode = 3;								
							}
							if (Mouse.y > 259 && Mouse.y < 325) {//ステージ選択
								Modechange = 120;
								nextmode = 1;
							}						
							if (Mouse.x > 187 && Mouse.x < 294 && Mouse.y > 336 && Mouse.y < 425) {//設定
								Modechange = 120;
								nextmode = 6;
							}
							if (Mouse.x > 319 && Mouse.x < 422 && Mouse.y > 336 && Mouse.y < 425) {//広告無効　要課金
								/*現時点では未実装*/
							}
						}
						//daen = pow(25, 2.0);
						daen = (double)(pow(Mouse.x - 90, 2.0) / pow(68, 2.0)) + (double)(pow(Mouse.y - 444, 2.0) / pow(25, 2.0)) - 1;
						if (daen  < 0) {//終了
							Modechange = 120;
							nextmode = 100;
						}						
					}
					
					break;
				case 1://StageLevel
					LevelSelect();
					if (Gamemode == 0) {
						nextmode = 0;
						Modechange = 120;
						Gamemode = 1;
					}
					if (Gamemode == 2) {
						nextmode = 2;
						Modechange = 120;
						Gamemode = 1;
					}
					break;
				case 2://StageSelect
					StageSelect();
					if (Gamemode == 1) {
						nextmode = 1;
						Gamemode = 2;
					}
					if (Gamemode == 3) {
						nextmode = 3;
						Gamemode = 2;
					}
					break;
				case 3://Game
					pl->click = Mouse.click;
					Game();
					if (Gamemode == 5) {						
						nextmode = Gamemode;
						Gamemode = 3;
					}
					if (Gamemode == 7) {
						nextmode = 3;
					}
					if (Gamemode == -1) {
						if (Config.recentstage == 0) {
							Config.recentstage = 101;
						}
						if (premode == 0) {
							level = (int)(Config.recentstage / 100);
							stage = Config.recentstage % 100;
						}
						penta.NewGame();
						for (int h = 1; h < 6; h++) {
							hINT hint = Stagedata[level][stage].Hint[h];
							penta.GetHint(h, hint.p, hint.x, hint.y, hint.angle);
						}
						penta.SetForbidden(Stagedata[level][stage].notturn, Stagedata[level][stage].notupset,stage);
						for (int p = 1; p < PIECECOUNT + 1; p++) {
							if (Stagedata[level][stage].notusep[p]) {
								penta.SetNotUse(p);
							}
							if (Stagedata[level][stage].Preset[p].x != 0) {
								penta.SetNotUse(p);
								penta.SetOnBoard(p, Stagedata[level][stage].Preset[p].x, Stagedata[level][stage].Preset[p].y, Stagedata[level][stage].Preset[p].angle);
							}
						}
						for (int x = 1; x < TWidth + 1; x++) {
							for (int y = 1; y < THeight + 1; y++) {
								if (Stagedata[level][stage].evil[x][y]) {
									penta.SetNotBoard(x, y);
								}
							}
						}
						penta.SetPlayerHand();
						Gamemode = 3;
					}
					break;
				case 4://Porse
					{
						DrawGraph(0, 0, img.porseholizon, true);
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
						DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 150);
						DrawGraph(180, 80, img.porse, true);
						string lavel = string(levelname[level]) + string(" - ") + to_string(stage);
						int age, font;
						GetStageLavel(age, font);
						DrawStringToHandle(300 - lavel.size() / 2 * 20, 30, lavel.c_str(), font, Font.Clear, age);
						if (Mouse.x > 209 && Mouse.x < 431) {
							SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
							if (Mouse.y > 179 && Mouse.y < 221) {
								//ゲームを続ける
								Gamemode = 3;
								DrawBox(210, 180, 430, 220, GetColor(250, 0, 0), true);

							}
							if (Mouse.y > 249 && Mouse.y < 291) {
								//ステージ選択に戻る
								Gamemode = 7;
								nextmode = 2;
								DrawBox(210, 250, 430, 290, GetColor(0, 250, 0), true);

							}
							if (Mouse.y > 319 && Mouse.y < 361) {
								//タイトルに戻る
								Gamemode = 7;
								nextmode = 0;
								DrawBox(210, 320, 430, 360, GetColor(200, 0, 250), true);

							}
							SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 200);
						}
						if (Mouse.click != 1) {
							//クリックされていないためPorseを続ける
							Gamemode = 4;
						}
						else {
							//クリックされた選択肢に応じてGamemodeを変える
							if (Gamemode != 4) {
								Mouse.click = 0;
								if (Gamemode == 7) {
									Sound(se.cancel);
								}
								else {
									Sound(se.button);
								}
							}
						}
					}
					break;
				case 5://Clear
					{
						int clevel = level;
						int cstage = stage - 1;
						if (Config.recentstage == level * 100 + stage) {
							if (cstage == 0) {
								clevel--;
								cstage = 20;
							}
						}
						else {
							cstage++;
						}
						DrawGraph(100, 100, img.clearboard, true);
						if (Mouse.click == 1 && Modechange == 0) {
							Modechange = 120;	
							if (level * 100 + stage != Config.recentstage || (level == 4 && cstage == 20)) {
								nextmode = 2;
								if (level == 4 && stage == 1 && Stagedata[level][stage].Hint[1].p == 0) {
									//Grave実装後に削除
									level = 3;
									stage = 20;
								}
							}
							else {
								nextmode = 3;								
							}
						}
						string lavel;
						lavel = levelname[clevel];
						lavel += string(" - ");
						lavel += to_string(cstage);
						lavel += string("  Clear!!");
						DrawStringToHandle(320 - lavel.size() / 2 * 20, 40, lavel.c_str(), GetColor(200, 200, 50), Font.Level, GetColor(10, 10, 10));
						int font = Font.Clear;
						int fs = 20;
						//if (level * 100 + stage != Config.recentstage) { //Grave実装後のコード
						//	lavel = string("タップしてステージ選択画面にもどる");
						//	font = Font.sClear;
						//	fs = 15;
						//}
						//else {
						//	lavel = string("タップして次のステージへ");
						//}
						if ((level * 100 + stage != Config.recentstage) || (level == 4 && cstage == 20)) {//レベルGraveが未実装の時のコード
							lavel = string("タップしてステージ選択画面にもどる");
							font = Font.sClear;
							fs = 15;
						}
						else {
							lavel = string("タップして次のステージへ");
						}
						//DrawStringToHandleで出力するとなぜか文字化けする →Font.Levelが日本語非対応だったことが判明
						//DrawString(320, 400, next, GetColor(0, 100, 250));
						
						DrawStringToHandle(320 - lavel.size() / 2 * fs, 400, lavel.c_str(), GetColor(200, 200, 50), font);
					}
					break;
				case 6://Setting
					Setting();
					if (Gamemode == 0) {
						nextmode = Gamemode;
						Gamemode = 6;
					}
					break;
				case 7://foolproof						
					{
					DrawGraph(0, 0, img.porseholizon, false);
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
					DrawBox(0, 0, 640, 480, GetColor(20, 20, 20), true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
					DrawBox(99, 89, 521, 411, GetColor(255, 255, 255), true);
					DrawBox(100, 90, 520, 410, GetColor(120, 120, 120), true);
					string msg;
					switch (nextmode) {
					case 0:
						msg = string("ここまでのプレイを終了しますか？");
						break;
					case 3:
						msg = string("本当にやり直しますか？");
						break;
					case 2:
						msg = string("ステージ選択に戻りますか？");
						break;
					}
					DrawStringToHandle(320 - (int)(msg.size() * 5) - 30, 120, msg.c_str(), GetColor(255, 255, 255), Font.sproof, GetColor(10, 10, 10));
					if (Mouse.y > 270 && Mouse.y < 295) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
						if (Mouse.x > 200 && Mouse.x < 270) {
							DrawBox(200, 270, 270, 295, GetColor(255, 0, 0), true);
						}
						if (Mouse.x > 360 && Mouse.x < 440) {
							DrawBox(360, 270, 440, 295, GetColor(0, 0, 255), true);
						}
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 150);
					}
					DrawStringToHandle(200, 270, "は い", GetColor(250, 250, 250), Font.bproof, GetColor(10, 10, 10));
					DrawStringToHandle(360, 270, "いいえ", GetColor(250, 250, 250), Font.bproof, GetColor(10, 10, 10));
					if (Mouse.y > 270 && Mouse.y < 295 && Mouse.click == 1) {
						if (Mouse.x > 200 && Mouse.x < 270) {							
							Modechange = 120;
							Sound(se.ok);
						}
						if (Mouse.x > 360 && Mouse.x < 440) {
							if (nextmode != 3) {
								Gamemode = 4;
								Mouse.click = 0;
							}
							else {
								Gamemode = 3;
							}
							Sound(se.cancel);
						}
					}
				}
					break;
				case 8://NewInfo
					NewiInfo();
					break;
				case 10://Movie
					break;
				}
				flame++;
				if (CheckHitKey(KEY_INPUT_LALT) == 1 && CheckHitKey(KEY_INPUT_F4) == 1) {
					r = 100;
				}
				if (Modechange > 0) {
					int param = 0;
					if (Modechange > 60) {
						if (Modechange == 120) {
							switch (Gamemode * 10 + nextmode) {
							case 1://01
							case 12:
							case 23:
							case 3://03
							case 42:
							case 47:
							case 52:
							case 53:
							case 70:
							case 72:
							case 6://06
							case 100://終了
								Sound(se.ok);
								break;
							case 10:
							case 21:
							case 43:
							case 60:							
								Sound(se.cancel);
								break;
							case 34:
							case 37:
								Sound(se.button);
								break;							
							case 35:
								Sound(se.clear);
								break;
							}
						}
						param = (int)(255 - 255 * (Modechange - 60) / 60);
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, param);
					}
					else {						
						if (Modechange == 60) {
							int premode = Gamemode;
							Gamemode = nextmode;
							Mouse.wheel = 0;
							int prebgm = CurrentBGM;//0～4,7で指定
							switch(nextmode) {
							case 0:
								if (premode != 1) {
									prebgm = 0;
								}
								break;
							case 1:
								level = 0;								
								break;
							case 2:
								stage = 0;
								if (premode == 5 || premode == 7) {
									prebgm = 0;
								}
								break;
							case 3:
								if (Config.recentstage == 0) {
									Config.recentstage = 101;
								}
								if (premode == 0) {
									level = (int)(Config.recentstage / 100);
									stage = Config.recentstage % 100;
								}
								{
									//int lstage;
									//LoadStageData(lstage, "./data/Stagedata.txt"); //デバッグ用
									if (Config.recentstage == 401 && level == 4) {
										//Grave実装後に削除
										level = 3;
										stage = 20;
									}
								}
								penta.NewGame();
								for (int h = 1; h < 6; h++) {
									hINT hint = Stagedata[level][stage].Hint[h];
									penta.GetHint(h, hint.p, hint.x, hint.y, hint.angle);
								}
								penta.SetForbidden(Stagedata[level][stage].notturn, Stagedata[level][stage].notupset, stage);
								for (int p = 1; p < PIECECOUNT + 1; p++) {
									if (Stagedata[level][stage].notusep[p]) {
										penta.SetNotUse(p);
									}
									if (Stagedata[level][stage].Preset[p].x != 0) {
										penta.SetNotUse(p);
										penta.SetOnBoard(p,Stagedata[level][stage].Preset[p].x, Stagedata[level][stage].Preset[p].y, Stagedata[level][stage].Preset[p].angle);
									}
								}
								for (int x = 1; x < TWidth + 1; x++) {
									for (int y = 1; y < THeight + 1; y++) {
										if (Stagedata[level][stage].evil[x][y]) {
											penta.SetNotBoard(x, y);
										}
									}
								}
								penta.SetPlayerHand();
								switch (Config.musicstyle) {
								case 0://デフォルト設定
									prebgm = (stage - 1) / 5 + 1;
									break;
								case 10://ランダム再生
									if (Config.recentstage > 600) {
										prebgm = GetRand(MUSIC - 1) + 1;
									}
									else {
										prebgm = GetRand(3) + 1;
									}
									break;
								default://指定されたbgmのみ再生
									prebgm = Config.musicstyle;
									break;
								}
								break;
							case 5:
								if (Config.recentstage == level * 100 + stage) {
									stage++;
									if (stage == 21) {
										level++;
										stage = 1;
									}
									Config.recentstage = level * 100 + stage;
								}
								break;
							case 100:
								r = 100;
								break;
							}
							if (prebgm != CurrentBGM) {
								StopSoundMem(bgm[CurrentBGM]);
								CurrentBGM = prebgm;
							}
						}
						param = (int)(255 * Modechange / 60);
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, param);
					}
					DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (nextmode == 5) {
						int g = (int)(120 - Modechange);
						if (Modechange < 60) {
							g = 60;
						}
						DrawGraph(40 + g, 40 + g, img.clearboard, true);
					}
					Modechange--;
					if (Modechange == 0) {
						Sound(CurrentBGM);
					}
				}
				//DrawFormatString(100, 100, GetColor(0, 0, 0), "Mouse.x = %d", Mouse.x);
				//DrawFormatString(100, 130, GetColor(0, 0, 0), "Mouse.y = %d", Mouse.y);
				//DrawFormatString(100, 100, GetColor(0, 0, 0), "Mouse.click = %d", Mouse.click);
				//DrawFormatString(100, 120, GetColor(0, 0, 0), "Mouse.clickcount = %d", Mouse.clickcount);
				//DrawFormatString(100, 180, GetColor(0, 0, 0), "daen = %f", daen);
				if (ScreenFlip() != 0) {
					r = -1;
				}
			}
			if (GetNowCount() - beforef < 1000) {
				//WaitTimer(GetNowCount() - beforef);
			}
		}
		DataSave();
	}
	//3点で構成される三角形の範囲内にカーソルが存在するかを計算します。返り値がtrueの時は範囲内であることを示します。
	bool TriangleRange(int ax,int ay,int bx,int by,int cx,int cy) {
		struct vec {			
			int x;//ベクトルのX成分
			int y;//ベクトルのY成分
			double abs;//絶対値
		};
		vec AB, BC, CA, AO, BO, CO;
		AB.x = (bx - ax);
		AB.y = (by - ay);
		AB.abs = sqrt(pow(bx - ax,2.0) + pow(by - ay, 2.0));
		BC.x = (cx - bx);
		BC.y = (cy - by);
		BC.abs = sqrt(pow(cx - bx, 2.0) + pow(cy - by, 2.0));
		CA.x = (ax - cx);
		CA.y = (ay - cy);
		CA.abs = sqrt(pow(ax - cx, 2.0) + pow(ay - cy, 2.0));
		AO.x = (Mouse.x - ax);
		AO.y = (Mouse.y - ay);
		AO.abs = sqrt(pow(Mouse.x - ax, 2.0) + pow(Mouse.y - ay, 2.0));
		BO.x = (Mouse.x - bx);
		BO.y = (Mouse.y - by);
		BO.abs = sqrt(pow(Mouse.x - bx, 2.0) + pow(Mouse.y - by, 2.0));
		CO.x = (Mouse.x - cx);
		CO.y = (Mouse.y - cy);
		CO.abs = sqrt(pow(Mouse.x - cx, 2.0) + pow(Mouse.y - cy, 2.0));
		double outABO, outBCO, outCAO;
		outABO = (AB.y * AO.x) - (AB.x * AO.y);
		outBCO = (BC.y * BO.x) - (BC.x * BO.y);
		outCAO = (CA.y * CO.x) - (CA.x * CO.y);
		if (ax > 500) {
			//DrawFormatString(100, 200, GetColor(0, 0, 0), "outABO = %f", outABO);
			//DrawFormatString(100, 220, GetColor(0, 0, 0), "outBCO = %f", outBCO);
			//DrawFormatString(100, 240, GetColor(0, 0, 0), "outCAO = %f", outCAO);
		}
		if (outABO > 0 && outBCO > 0 && outCAO > 0) {
			return true;
		}
		else {
			return false;
		}

	}
	void UpdateMouseCondition() {	
		Mousebefore.x = Mouse.x;
		Mousebefore.y = Mouse.y;
		Mousebefore.clickbutton = Mouse.clickbutton;
		Mousebefore.clickcount = Mouse.clickcount;
		Mousebefore.clicklog = Mouse.clicklog;
	}
	void GetMouseCondition() {
		int m = GetMouseInputLog2(&Mouse.clickbutton, &Mouse.x, &Mouse.y, &Mouse.clicklog, TRUE);
		
		if (m < 1) {
			//マウス処理
			Mouse.wheel += GetMouseWheelRotVol() * -10;
			if (Mouse.clickbutton == MOUSE_INPUT_LEFT) {
				if (Mousebefore.clicklog == MOUSE_INPUT_LOG_UP && Mouse.clicklog == MOUSE_INPUT_LOG_DOWN) {//1フレーム中にマウスがクリックされた場合
					Mouse.clickcount++;//1フレーム中のクリック数をカウント
					Mouse.click = 4;//マウスをクリックしたまま				
				}
			}
			if (Mousebefore.clicklog == MOUSE_INPUT_LOG_DOWN && Mouse.clicklog == MOUSE_INPUT_LOG_UP) {//1フレーム中にマウスボタンが離された場合
				Mousebefore.click = Mouse.click;
				switch (Mouse.clickcount) {
				case 1:
					Mouse.click = 1;//シングルクリック		
					Mouse.clickf = GetNowCount();
					break;
				case 2:
					Mouse.click = 2;//ダブルクリック
					Mouse.clickcount = 0;
					break;
				}
			}
			if (Mousebefore.clicklog == MOUSE_INPUT_LOG_UP && Mouse.clicklog == MOUSE_INPUT_LOG_UP) {//1フレーム中にマウスボタンが離された場合
				if (Mouse.clickf > 0 && GetNowCount() - Mouse.clickf >= 60) {
					Mouse.click = 0;
					Mouse.clickcount = 0;
					Mouse.clickf = 0;
				}
			}
			GetMousePoint(&Mouse.x, &Mouse.y);
			if (Mousebefore.clicklog == MOUSE_INPUT_LOG_DOWN && Mouse.clicklog == MOUSE_INPUT_LOG_DOWN && (Mousebefore.x != Mouse.x || Mousebefore.y != Mouse.y)) {//1フレーム中にマウスボタンが押され続けた場合
				Mouse.click = 3;//ドラッグ状態
			}
			if (Mouse.clickf > 0 && GetNowCount() - Mouse.clickf >= 500) {
				Mouse.clickcount = 0;
				Mouse.clickf = 0;
			}
		}
		else {
			//タッチパネル処理
			if (GetTouchInputNum() > 0) {
				//タッチパネルをタップしている
				m = GetTouchInput(0, &Mouse.x, &Mouse.y, NULL, NULL);
				switch (Mousebefore.click) {
				case 0:
					Mouse.click = 4;
					break;
				case 2:
					Mouse.click = 0;
					Mouse.clickcount = 0;
					break;
				case 3://Mouse.yの変化に応じてスクロール処理をする
					Mouse.wheel += Mouse.y - Mousebefore.y;
					break;
				case 4:
					if (Mousebefore.x != Mouse.x || Mousebefore.y != Mouse.y) {
						Mouse.click = 3;
					}
					break;
				}
			}
			else {
				//タッチパネルに触れていない
				switch (Mousebefore.click) {
				case 0:
					if (Mouse.clickf > 0 && GetNowCount() - Mouse.clickf >= 60) {
						Mouse.click = 0;
						Mouse.clickcount = 0;
						Mouse.clickf = 0;
					}
					break;
				case 1:
				case 3:
				case 4:				
					Mousebefore.click = Mouse.click;
					Mouse.clickcount++;
					if (Mouse.clickcount == 1) {
						//シングルタップ
						Mouse.click = 1;
						Mouse.clickf = GetNowCount();
					}
					else {
						//ダブルタップ
						Mouse.click = 2;
						Mouse.clickcount = 0;
					}
					break;
				case 2:
					Mouse.click = 0;
					Mouse.clickf = 0;
					break;
				
				}

			}
			if (Mouse.clickf > 0 && GetNowCount() - Mouse.clickf >= 500) {
				Mouse.clickcount = 0;
				Mouse.clickf = 0;
			}
		}
		//DrawFormatString(100, 80, GetColor(0, 0, 0), "Mouse.clickbutton = %d", Mouse.clickbutton);
		
		//DrawFormatString(100, 120, GetColor(0, 0, 0), "Mouse.x = %d", Mouse.x);
		//DrawFormatString(100, 140, GetColor(0, 0, 0), "Mouse.y = %d", Mouse.y);
		//DrawFormatString(100, 160, GetColor(0, 0, 0), "Mouse.clickcount = %d", Mouse.clickcount);
		//DrawFormatString(100, 180, GetColor(0, 0, 0), "Mouse.clicklog = %d", Mouse.clicklog);
		//DrawFormatString(100, 200, GetColor(0, 0, 0), "Mouse.clickf = %d", Mouse.clickf);
	}
	//引数sには、SEの場合は構造体seのハンドルを直接指定し、bgmはトラック番号を指定してください
	void Sound(int s) {
		int r = 0;		
		if (s < 10) {
			//BGM
			if (Config.bgm && CheckSoundMem(bgm[s]) == 0) {
				StopSoundMem(bgm[CurrentBGM]);
				r = PlaySoundMem(bgm[s], DX_PLAYTYPE_LOOP, true);
				ChangeVolumeSoundMem(192, bgm[s]);
				CurrentBGM = s;
			}

		}
		else {
			//SE
			if (Config.se ){
				if (CheckSoundMem(s) == 0 || startSE + 400 < GetNowCount()){
					r = PlaySoundMem(s, DX_PLAYTYPE_BACK, true);
					ChangeVolumeSoundMem(192, s);
					startSE = GetNowCount();
				}
			}
		}
		if (r == -1) {
			r = -1;
		}
	}
	//読み込まれたステージデータからヒントを作成し別のファイルに出力します。
	void CreateStageHintData() {
		int laststage;
		ClearStageData();
		LoadStageData(laststage, "./Data/Stageprotodata.csv");
		int flame;
		int r;
		SetDrawScreen(DX_SCREEN_BACK);
		int level = 0;
		int second;//20秒ごとにやり直す
		int stage = 1;//
		int trycount;//試行回数が200になった終了し、次のステージをソートする。
		for (int s = 1; s < laststage + 1; s++) {
			if (s % 20 == 1) {
				level++;
			}
			stage = s - (level - 1) * 20;
			if (StartSort(level, stage) == 1) {
				r = 1;
			}
			else {
				r = 0;
			}
			second = 0;
			trycount = 0;
			while (ProcessMessage() == 0 && r == 0) {
				flame = 1;
				second++;
				while (ClearDrawScreen() == 0 && flame < 31 && r == 0) {//fps 30
					UpdateMouseCondition();
					GetMouseCondition();
					flame++;
					if (CheckHitKey(KEY_INPUT_LALT) == 1 && CheckHitKey(KEY_INPUT_F4) == 1) {
						r = 100;
					}
					if (second == 2) {
						second = 0;
						trycount++;
						if (StartSort(level, stage) == 1 && trycount < 200) {
							r = 1;
						}
						else {
							r = 0;
						}
					}
					if (srt.AllPieceSet() == false && srt.AllTableSet() == false) {
						srt.sort();
					}
					else {
						//盤面完成
						r = 1;
						hINT  * hint;						
						for (int h = 1; h < 6; h++) {
							hint = &Stagedata[level][stage].Hint[h];
							srt.GetHint(hint->p, hint->angle, hint->x, hint->y, h);
						}
						
					}
					srt.DisplaySortBoard(true);
					DrawFormatString(50, 300, GetColor(150, 150, 150), "level stage = %d - %d", level,s);
					if (CheckHitKey(KEY_INPUT_SPACE) == 1) {
						WaitKey();
					}
					if (ScreenFlip() != 0) {
						r = -1;
					}
					if (r == 1) {
						string file = to_string(level) + string(" - ") + to_string(s) + string(".bmp");
						SaveDrawScreen(0, 0, 639, 479, file.c_str());
					}
				}				
			}
		}
		HintSave(laststage, "./Data/Stagedata.txt", "./Data/Stageprotodata.csv");
	}
	//回転操作が禁止されると同時に他の制約がない状態でソートを行い、残りピース数に応じてクリアとみなして、その状態の盤面画像を保存します。
	void CreateClearDataOfNotTurn() {
		int second;//2秒ごとにやり直す
		int r;
		int flame;
		int restp;
		for (int rest = 3; rest > 2; rest--) {//余剰ピース数
			for (int pat = 1; pat < 4; pat++) {//ステージ番号に応じて初期設定されるパターン番号
				for (int s = 1; s < 11; s++) {//10ステージ分制作する。
					if (pat != 1 || s != 1) {
						srt.startsort(s);
						srt.SetForbidden(true, false, pat);
						srt.SetRestPiece(rest);
						srt.startsort2();
						second = 0;
						r = 0;
						while (ProcessMessage() == 0 && r == 0) {
							flame = 1;
							second++;
							while (ClearDrawScreen() == 0 && flame < 31 && r == 0) {//fps 30							
								if (second == 2) {
									second = 0;
									srt.startsort(s);
									srt.SetForbidden(true, false, pat);
									srt.SetRestPiece(rest);
									srt.startsort2();
								}
								restp = 0;
								for (int p = 1; p < PIECECOUNT + 1; p++) {
									if (srt.Player.play[p] == -1) {
										restp++;
									}
								}
								if (restp < PIECECOUNT - rest) {
									srt.sort();
								}
								else {
									//盤面完成
									r = 1;
								}
								srt.DisplaySortBoard(true);
								DrawFormatString(50, 300, GetColor(150, 150, 150), "pat %d - %d    restp = %d", pat, s, restp);
								if (ScreenFlip() != 0) {
									r = -1;
								}
								if (r == 1) {
									_chdir("NotTurn");
									string file = string("rest") + to_string(rest) + string("_") + string("pat") + to_string(pat) + string(" - ") + to_string(s) + string(".bmp");
									SaveDrawScreen(0, 0, 639, 479, file.c_str());
									FILE  * savedata;
									fopen_s(&savedata, "hint.txt", "a");
									hINT  hint;
									string save = string("");
									for (int h = 1; h < 6; h++) {
										srt.GetHint(hint.p, hint.angle, hint.x, hint.y, h);
										if (h > 1) {
											save += string("-");
										}
										else {
											save = string("rest") + to_string(rest) + string("_") + string("pat") + to_string(pat) + string(" - ") + to_string(s) + string(":");
										}
										//ppxxyyaa
										save += (hint.p < 10) ? string("0") + to_string(hint.p) : to_string(hint.p);
										save += (hint.x < 10) ? string("0") + to_string(hint.x) : to_string(hint.x);
										save += (hint.y < 10) ? string("0") + to_string(hint.y) : to_string(hint.y);
										save += string("0") + to_string(hint.angle);

									}
									fputs(save.c_str(), savedata);
									fputs("\n", savedata);
									fclose(savedata);
									_chdir("..");
								}
								flame++;
							}
						}
					}
				}
			}
		}
	}
	void ClearStageData() {
		for (int level = 1; level < 8; level++) {
			for (int stage = 1; stage < 21; stage++) {
				Stagedata[level][stage].notturn = false;
				Stagedata[level][stage].notupset = false;
				for (int x = 1; x < TWidth + 1; x++) {
					for (int y = 1; y < THeight + 1; y++) {
						Stagedata[level][stage].evil[x][y] = false;
					}
				}
				for (int p = 1; p < PIECECOUNT + 1; p++) {
					Stagedata[level][stage].Preset[p].x = 0;
					Stagedata[level][stage].Preset[p].angle = 0;
					Stagedata[level][stage].Preset[p].y = 0;
					Stagedata[level][stage].notusep[p] = false;
				}
			}
		}
	}	
	int StartSort(int level,int stage) {
		
		if (Stagedata[level][stage].Hint[1].p != 0) {
			//ヒントデータ作成済み
			return 1;
		}
		srt.startsort(stage);
		srt.SetForbidden(Stagedata[level][stage].notturn, Stagedata[level][stage].notupset, level * 10 + stage);
		int rest = 0;
		for (int p = 1; p < PIECECOUNT + 1; p++) {
			if (Stagedata[level][stage].notusep[p]) {
				rest -= 5;
				srt.SetNotUse(p);
			}
			if (Stagedata[level][stage].Preset[p].x > 0) {
				
				srt.SetOnBoard(p, Stagedata[level][stage].Preset[p].x, Stagedata[level][stage].Preset[p].y, Stagedata[level][stage].Preset[p].angle);
			}
		}
		
		for (int x = 1; x < 11; x++) {
			for (int y = 1; y < 7; y++) {
				if (Stagedata[level][stage].evil[x][y]) {
					srt.SetNotBoard(x, y);
					rest++;
				}
			}
		}
		if (rest < 0) {
			//盤面積＞ピース面積
			return -1;
		}
		else {
			rest /= 5;
			srt.SetRestPiece(rest);
		}
		srt.startsort2();
		return 0;
	}
private:
	int Gamemode;//ゲーム内の状態を示す変数。0.Title 1.StageLevel 2.StageSelect 3.Game 4.Porse 5.Clear 6.Setting 7.fproof(確認画面) 8.NewInfo 10.Movie(広告？)
	int stage;//プレイ中のステージNoを示す変数。StageSelectにて設定される。1～20
	int level;//プレイ中のステージレベルを示す変数。LevelSelectにて設定される。
	char * levelname[8];//Lento	 Adagio	 Andante  Grave	 Animato  Allegro  Presto
	string proofword;//確認用画面にて表示される文字列。最初からボタンの場合は「本当にやり直しますか？」、Porseボタンの場合は「ここまでのプレイを終了しますか？」
	double Modechange;//モードチェンジ中のエフェクト時間(フレーム単位)を示す変数。これが1以上の間はマウス操作を受け付けない
	struct IMAGE {
		int title;//タイトル画面の背景画像
		int levelselect;//レベル選択画面での背景画像
		int stageselect;//ステージ選択画面での背景画像
		int lockedstage;//ロック中のステージアイコン
		int playablestage;//プレイ可能なステージアイコン
		int clearedstage;//クリア済みのステージアイコン
		int clearedlevel;//クリア済みのレベルアイコン
		int porse;//ポーズ中に表示されるポーズラベル
		int porseholizon;//ポーズ中の背景画像。ポーズ前のゲーム画面がキャプチャされる。
		int clearboard;//クリア時の盤面画像
		int lv[8];//1～7がLevelSelectで使われる。
		int lock;//ロック中のレベル・ステージを示すアイコン。
		int unlocked;//課金・広告視聴、または前レベルオールクリア時の演出で使われるアンロックアイコン。
		int nextp;//メインピース枠内にピースがある場合に枠内右側にあるボタンをクリックすることで別のピースをメインに回します。
		int setting;//設定画面にて表示される画像です。画像内の文字にカーソルを合わせてクリックことで設定を変更できます.
		int mselect;//BGMを選択をするボタンの画像です。ボタンがクリックされた時に表示されます。またbgmがfalseの時は反応しません。画像は右方向だが左方向は反転して描写する。
	};
	IMAGE img;
	struct cONFIG {//これらの設定はプレイヤーのID毎に記録される。
		int id;//プレイヤーを識別するためのID。メールアドレスやプレイ時の日時、1日あたりのプレイ回数などで登録。現時点では未実装。
		string name;//プレイヤー名。ランキング登録などに使用されます。
		//bool righty;//プレイヤーが右利きかどうかを示す変数。デフォルトでtrueだが設定で変更できる。
		int minostyle;//ピースの柄を設定できる。デフォルトでは柄なし。レベルLentoクリア時に選べるようになり、次以降のレベルクリア時に柄が追加されていく
		bool bgm;//ゲーム中にBGMを流すかどうかを示す変数。trueの時は流れるがfalseの時は流れない。
		bool se;//ゲーム中に効果音を付けるかどうかを示す変数。trueの時は音が出るがfalseの時はない。
		int musicstyle;//音楽に関する設定。デフォルトではランダムで流れるがプレイヤーによる指定もできる。0.デフォルト,1～ 指定されたbgmのみ 10.ランダム再生。またbgmがfalseだと設定できない。
		int recentstage;//直前までプレイしていたゲームステージ番号。つづきからで開始する場合この番号を元にゲームを開始する。100の桁がレベル番号(1～7)、10の桁がステージ番号(1～20)を示す。
		bool fproof;//最初からボタンやステージ選択・タイトルに戻る時の誤操作を防止するための確認画面を出すかどうかの変数。falseの時は確認画面を出さずに処理を行う。
	};
	cONFIG Config;
	struct hINT {
		int x;//表示するピースの左上X座標
		int y;//表示するピースの左上Y座標
		int angle;//表示するピースのアングル(0～7)
		int p;//表示するピースの座標(1～12)
		//bool displayed;//ヒントが表示されたかを示す変数。trueの時は上記変数を元にピースの影を表示する。またステージ開始時にリセット(全てfalse)する。
	};
	struct pRESET {
		int x;
		int y;
		int angle;
	};
	struct sTAGEDATA {
		hINT Hint[6];//[ヒント数1～5]
		
		bool notupset;//このステージにおいて反転が禁止されているかを示す。trueの時は禁止。
		bool notturn;//このステージにおいて回転操作が禁止されているかを示す。trueの時は禁止。
		bool notusep[PIECECOUNT + 1];//このステージにおいて使用されないピースかどうかを示す。trueの時は未使用。
		pRESET Preset[PIECECOUNT + 1];//このステージにおいて予め設置済みであるピースを示す。設置済みの時はpRESET構造体に情報が入力される。またPresetで設置済みとなったピースは使用不可Notusepにも登録される。
		bool evil[TWidth + 1][THeight + 1];//[1～10][1～6]が盤面に対応。ピースが設置できない盤面を示す。trueの時はTable[x][y].boardが-1になります。
	};
	sTAGEDATA Stagedata[8][21];//[レベル1～7][ステージ1～20]
	struct sE {
		int ok;//決定音
		int cancel;//キャンセル時、またはピースを元に戻した時の音
		int select;//ステージ選択時、待ちピースからメインピースに据える時、選択状態のピースを回転・反転させる時、ポーズ画面から文字列にカーソルを当てた時、元に戻す、初めからを押した時の音
		int clear;//ステージクリア時の音
		int button;//ポーズ、ヒントボタンを押した時の音
		//int touch;//ピースを選択状態にした時の音。 selectに統合
		int set;//ピースを盤面に設置した時の音。
	};
	sE se;	
	int bgm[MUSIC + 1];//BGMは7曲収録予定だが、4曲のみにとどまる事も。0.Title,1～Game内で使用される曲
	int CurrentBGM;//現在再生中のBGM番号です。0～4,7で指定
	int startSE;//効果音が再生された時の時間を保存します。ダブリ音防止のため再生後しばらくしてから同じ音を再生します。
	struct mOUSE {
		int x;//カーソルのX座標。
		int y;//カーソルのX座標。
		int clickcount;//1フレーム中に左ボタンをクリックした回数を保持する変数。
		int clickf;//最初にクリックされた時のフレーム数。これが500Fを超える前に再度クリックされたらダブルクリックとなる。
		int clicklog;//ボタンが押されたのか離されたのかを示す変数。
		int clickbutton;//クリックされたボタンの種類。基本は左クリックのみで操作可能
		int click;//クリックの種類。0.押されていない 1.シングルクリック 2.ダブルクリック 3.ドラッグ 4.クリックしたまま動かない
		int wheel;//ホイールの回転量。プラスの場合は画面を下にスクロールし、マイナスの場合は上にスクロールします。
	};
	mOUSE Mouse;
	mOUSE Mousebefore;
	struct fONT {
		int bproof;//確認画面で使われる大きいフォント
		int sproof;//確認画面で使われる小さいフォント
		int Level;//レベル名を表示するときに使われるフォントデータです。PENTAコントラクタで設定されます。日本語非対応
		int Clear;//クリア画面にて使われるフォント
		int sClear;//クリア画面にて使われるフォントの小さい方
	};
	fONT Font;
	int minostyle[10];//ピースの柄のスタイル別画像。Lentoクリアから選択可能となり、Settingにて設定できる。またゲーム開始時にConfig.minostyleからピースの柄を変更する。
	//0.初期,1～3.Lento,4～5.Andante,6～7.Grave,8～9.Allegro
	int newinfo;//ゲームの進行状態に応じて表示されるゲームの新情報です。
	
	/*
	0.チュートリアル(設置不可マス、設置済みピース、使用不可ピースの説明,各種ボタンの説明
	1.Lentoクリア&ピース柄の選択が可能に 
	2.Adagioクリア&BGMの形式の選択が可能に 
	3.Andanteクリア&新しい柄の追加 
	4.Graveクリア&新しい柄の追加
	5.Animatoクリア&新しいBGMの追加と選択可
	6.Allegroクリア&新しい柄の追加
	7.Prestoクリア&広告機能の停止
	10.回転禁止・反転禁止の説明
	11.Borderの説明 //未定
	12.盤面上下ボタンの説明 //未定
	*/
};
