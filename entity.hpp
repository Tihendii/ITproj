#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Entity {
public:
	float dx, dy, x, y, speed, moveTimer;
	int w, h, health;
	bool life, isMove;
	Texture texture;
	Sprite sprite;
	string name;
	Entity(Image& image, float X, float Y, int W, int H, string Name) {
		x = X; y = Y; w = W; h = H; name = Name; moveTimer = 0;
		speed = 0; health = 100; dx = 0; dy = 0;
		life = true; isMove = false;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
	}
};
class Player :public Entity {
public:
	enum { left, right, up, down, stay } state;//��������� �������

	Player(Image& image, float X, float Y, int W, int H, String Name) :Entity(image, X, Y, W, H, Name) {
		if (name == "�������� �������") {
			//sprite.setTextureRect(IntRect(, w, h));�������� ��������
		}
	}

	void control() {
		if (Keyboard::isKeyPressed) {//����� �������� ������� ������ ����������
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				state = left; speed = speed;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				state = right; speed = speed;
			}

			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				state = up; speed = speed;
			}

			if (Keyboard::isKeyPressed(Keyboard::Down)) {
				state = down; speed = speed;
			}
		}
	}

	void checkCollisionWithMap(float Dx, float Dy)//� ��� �������� ������������ � ������
	{
		/**for ()//���������� �� ��������� �����
			for ()
			{
				if (Map[i][j] == '1')
				{
					if (Dy > 0) {}//�� Y ����=>���� � ���(����� �� �����).
					if (Dy < 0) {}//������������ � �������� ������ �����
					if (Dx > 0) {}//� ������ ����� �����
					if (Dx < 0) {}// � ����� ����� �����
				}
			}
	*/
	};
	void update(float time)
	{
		control();//������� ���������� ����������
		switch (state)//��� �������� ��������� �������� � ����������� �� ���������
		{
		case right:dx = speed; break;//��������� ���� ������
		case left:dx = -speed; break;//��������� ���� �����
		case up: dy = speed; break;
		case down: dy = -speed; break;
		case stay: break;		
		}
		x += dx * time;
		checkCollisionWithMap(dx, 0);//������������ ������������ �� �
		y += dy * time;
		checkCollisionWithMap(0, dy);//������������ ������������ �� Y
		sprite.setPosition(x + w / 2, y + h / 2); //������ ������� ������� � ����� ��� ������
		if (health <= 0) { life = false; }
		if (!isMove) { speed = 0; }
		//if (life) { setPlayerCoordinateForView(x, y); } ����� ��������, ���� ������ �� ������ ���� ��� ����������
	}
};
class Enemy :public Entity {
public:
	Enemy(Image& image, float X, float Y, int W, int H, String Name) :Entity(image, X, Y, W, H, Name) {
		if (name == "EasyEnemy") {
			sprite.setTextureRect(IntRect(0, 0, w, h));
			dx = 0.1;//���� ��������.���� ������ ������ ���������
		}
	}
	void checkCollisionWithMap(float Dx, float Dy)
	{
		for (int i = y / 32; i < (y + h) / 32; i++)
			for (int j = x / 32; j < (x + w) / 32; j++)
			{//����� ���������� ����, �������� ����������� ����� ������� �����, ��� ����� �� �� ��������
				/*if (TileMap[i][j] == '0')//���� ������� ��� ������ �����, ��
				{
					if (Dy > 0) { y = i * 32 - h; }//�� Y ����=>���� � ���(����� �� �����) ��� ������. � ���� ������ ���� ���������� ��������� � ��������� ��� �� �����, ��� ���� ������� ��� �� �� ����� ��� ����� ����� ����� �������
					if (Dy < 0) { y = i * 32 + 32; }//������������ � �������� ������ �����(����� � �� �����������)
					if (Dx > 0) { x = j * 32 - w; dx = -0.1; sprite.scale(-1, 1); }//� ������ ����� �����
					if (Dx < 0) { x = j * 32 + 32; dx = 0.1; sprite.scale(-1, 1); }// � ����� ����� �����
				}
			}
		*/
			};
	};
	void update(float time)
	{
		if (name == "EasyEnemy") {//������� ������� ����
			//moveTimer += time;if (moveTimer>3000){ dx *= -1; moveTimer = 0; }//������ ����������� �������� ������ 3 ���
			checkCollisionWithMap(dx, 0);
			x += dx * time;
			sprite.setPosition(x + w / 2, y + h / 2); //������ ������� ������� � ����� ��� ������
			if (health <= 0) { life = false; }
		}
	}
};