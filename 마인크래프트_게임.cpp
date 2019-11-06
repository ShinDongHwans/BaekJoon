#include <stdio.h>
#include <string.h>
char portion[2];
int turn;

class unit{
	private:
		int HP;
		int ATK;
	public:
		void set(int _HP, int _ATK);
		void damaged(int damage);
		int deal();
		int buff(char x[], int up);
		int alive();
};

void unit::set(int _HP, int _ATK){
	HP=_HP;
	ATK=_ATK;
}

void unit::damaged(int damage){
	HP-=damage;
}

int unit::deal(){
	return ATK;
}

int unit::buff(char x[] ,int up){
	if(x[0]=='*')
		return ATK*up;
	else
		return ATK+up;
}

int unit::alive(){
	if(HP>0)
		return 0;
	return 1;
}
unit hero, enemy;
int enemy_turn();

int hero_turn(){
	if(turn){
		enemy.damaged(hero.buff(portion, portion[1]-48));
		turn--;
	}
	else
		enemy.damaged(hero.deal());
	
	if(enemy.alive())
		return 1;
	else
		return enemy_turn();
		
}

int enemy_turn(){
	hero.damaged(enemy.deal());
	if(hero.alive())
		return 0;
	else
		return hero_turn();
}


void engage(){
	printf("%d", hero_turn());
}

int main(){
	int HP=0, ATK;
	int amor;
	int buy;
	
	for(int i=0;i<4;i++){
		scanf("%d", &amor);
		HP+=amor;	
	}
	scanf("%d", &ATK);
	hero.set(HP, ATK);
	
	scanf("%d", &buy);
	if(buy)
		scanf("%s %d", &portion, &turn);
	scanf("%d %d", &ATK, &HP);
	enemy.set(HP, ATK);
	
	engage();
}
