#include "Rpg.h" // Exportando funcoes para outro arquivo
#include <iostream>

using namespace rpg;
using namespace std;

/*   --- ANOTAÇÕES ---

// Jairo

	Professor Falo que provavelmente vamo ta mechendo nesse trabalho nas outras M's entao quero deixar pronto pra podermos expandir. XD

IDEIA:  // Passem as de vcs pra gente entrar num acordo  
 - Fazer os stats serem pequenos com grande difereça pra fazer o jogo meio dificil.
 - Magia vai ser escassa e meio que um cheat ignorando armadura(Ca).

Funcionamento:
 - Vo usar heranca pra fazer as structs.
 - Quero que tenha um mapa:
	- Esse mapa vai ser só um array 9x9 por lvl com os inimigos em posiçoes aleatorias.
	- uma saida e uma entrada aleatoria tbm (mas spre nas bordas).
 - Nomes:
	- pensei em alguns arrays com varios nomes.
	- uma função que seleciona eles aleatoriamente.
	- assim as armas teriam nomes spre diferentes. :) - So its more cool


// Romulo


// Diogo

*/


struct Entity {
	// Base pra os seres vivos do game: player, inimigos ...
	
	private: // lest make things more safe and complex :)
		// só pode ser modificada aqui

		int _Life; // Vida = VIDA_BASE * LEVEL + VIDA_BASE * Str / 2 
		int _Ca;   // classe de armadura - Quão dificil é acertar :)
		// Ca = Ca_BASE * LEVEL + Ca BASE * Dex / 2

		int _Str;
		int _Dex;
		int _Int;

		int _Lvl; 

	protected: 
		// só pode ser modificada aqui e em subclasses

		void SetLife(int value) { _Life = value; };
		void SetCa(int value)   { _Ca = value;   };
		void SetStr(int value)  { _Str = value;  };
		void SetDex(int value)  { _Dex = value;  };
		void SetInt(int value)  { _Int = value;  };
		void SetLvl(int value)  { _Lvl = value;  };

	public:
		// modificada em qlqr lugar

		int GetLife() { return _Life; };
		int GetCa()   { return _Ca;   };
		int GetStr()  { return _Str;  };
		int GetDex()  { return _Dex;  };
		int GetInt()  { return _Int;  };
		int GetLvl()  { return _Lvl;  };
};

struct Player : Entity {
	private:
		int _Xp;
		int _levels[3] = {100, 300, 900};

	protected:
		void SetXp(int value) { _Xp = value; };

		
		void CalcLevel(){
			for(int i = 0; i < 3; i++){
				if (_Xp > _levels[i]){
					SetLvl(i+1);
				};
			};
		};

	public:
		int GetXp() { return _Xp; };
};

