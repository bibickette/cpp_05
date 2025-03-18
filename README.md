# cpp notes

# declarer une class dans un .hpp
class Name
{
	private:
		type _name; (avec un _devant les variables private)
	public:
	Name(); (constructeur)
	Name(arg); (constructeur avec arg, a quand meme besoin
	dun constructeur lambda au debut)
	~Name(); (destructeur)
}


# declarer les constructeurs dans le .cpp
2 types de declarations:
1. declaration sans arguments avec un constructeur vide
{ Name::Name() : _name("") {} }
Name:: designe la fonction qui sera dans la class Name
Name() est le constructeur
_name("") on met la variable name a vide (il faut le faire pour toutes les variables privées mises dans la class)

2. declaration avec arguments
{ Name::Name(arg){ _name = arg; } }
on attribue arg au _name qui est privée


# declarer un destructeur dans le .cpp
{ Name::~Name() {} }
~Name() est le destructeur
On met quelque chose dedans seulement si il faut manuellement delete
sinon le compilateur appellera le destructeur correspondant
de chaque variable


# acceder a une variable privée
# getter
dans la class, en public, on declarera une fonction getter
cette fonction renverra linformation privée que lon souhaite
dans le .hpp
{ class Name
	{
	public:
		type getter(arg or void); 
	}
}
dans le .cpp
{	type Name::getter(arg or void)
	{ return(_privatevar); }
}

Comment utiliser ?
dans une fonction on declare notre variable et on va lire le getter
{
	// avant il faut lavoir declarer
	Name pouet = Name();
	cout << pouet.getter() << endl;
	// on va juste imprimer la variable
}
# setter
dans la class, en public, on declarera une fonction setter
cette fonction mettra linformation privée que lon souhaite
dans le .hpp
{ class Name
	{
	public:
	void setter(arg or void); 
	}
}
dans le .cpp
{	void Name::setter(arg)
	{ _privatevar = arg; }
}

Comment utiliser ?
dans une fonction avec une variable declarée, on appelle le setter
{
	Name pouet = Name(); // on construit dabord
	pouet.setter(arg);
	cout << pouet.getter() << endl; // on peut print notre var
}


# les statics dans les class
lorsquune variable static est declarée dans un .hpp dans une class
elle nest pas directement initialisée a 0
{ private: (je suppose que c aussi pour public)
		static type _var; }
il faut la declarer dans le .cpp (hors fonction tout en haut comme le using)
{ type Name::_var = 0; }


# allocations
# allouer une class
pour allouer on utiliser le mot clef { new } devant la class
{ Name *pouet = new Name(); 
  delete pouet; }
il ne faut pas oublier de delete a la fin

# allouer un tab de class
pour allouer un tab, on rajout juste le [] du tab
{ Name *pouetTab = new Name[nb dalloc];
  delete []pouetTab; }
pour delete un tab on oublie pas [] devant le tab


# adress et reference
# "explications"
{
	std::string string = "HI THIS IS BRAIN";

	std::string *stringPTR;
	stringPTR = &string;
	/* une & declarée doit etre initialisée immediatement */

	std::string &stringREF = string;
}
*stringPTR est un pointeur qui stockera une adresse, ici on donne l'adresse de string
si string est modifié alors le resultat sappliquera aussi sur le pointeur
car il pointera toujours l'adresse de string

&stringREF est une autre façon d’accéder à string, mais il ne stocke pas d’adresse comme un pointeur.
- doit être initialisée immédiatement.
- ne peut pas être modifiée pour référencer une autre variable.

{
	// memory adress
	cout << "string : " <<  &string << endl;

	cout << "stringPTR : " << stringPTR << endl;
	/*  stringPTR tiens ladresse de string, si on met &stringPTR
	alors cest ladresse de stringPTR la ou il est stocké et pas son
	adresse tenue */

	cout << "stringREF : " << &stringREF << endl;
	/* comme la ref de stringREF est string, alors cest la meme adresse
	a lutilisation */

	// print value
	cout << "string : " << string << endl;
	cout << "stringPTR : " << *stringPTR << endl;
	cout << "stringREF : " << stringREF << endl;
}

# utilisations
1. donner une adresse pour lier deux objets
{
	// dans le main :
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);

	// mon constructeur :
	HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {}
	/* je nai pas de constructeur vide dans ma structure ici */

	// mon .hpp :
	private:
		std::string _name;
		Weapon &_weapon;
}
ici mon constructeur prend l'adresse d'un objet, donc tout ce qui sera modifier a lobjet sera lié par ladresse et donc tout restera coordonnée et les
effets sappliqueront partout

2. lier deux objets par un pointeur
{
	// dans le main :
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);

	// mon constructeur :
	HumanB::HumanB(std::string name): _name(name) {}

	// attribuer a un pointeur : 
	void HumanB::setWeapon(Weapon weapon) { *_weapon = weapon; }

	// mon .hpp
	private:
		std::string _name;
		Weapon *_weapon;
}
ici ma class possede un pointeur donc il nest pas obligé detre initialisé immediatement, je peux donc appeler une fonction pour lier ce pointeur a la variable que je veux


# pointeurs sur fonctions
un pointeur sur fonction permet deviter les forets de if/else
permet de faire plusieurs actions

{
	// dans notre class Harl
	private:
		void debug( void );
		void info( void );
		void warning( void );
	public:
		void complain( std::string level );

	// nos fonctions
	void Harl::debug( void ) { cout << "[ DEBUG ]" << endl; }
	void Harl::info( void ) { cout << "[ INFO ]" << endl; }
	void Harl::warning( void ) { cout << "[ WARNING ]" << endl; }
}
dans les exemples, tout se passe dans harl::complain

1. stocker une fonction dans un pointeur
{
	void(Harl::*ptr) (); // créer un pointeur
	ptr = &Harl::debug; // attribuer la fonction au pointeur
	if(level == "DEBUG")
		(this->*ptr)(); // pour utiliser

}
le this permet dutiliser sur lobjet sur lequel on est ici, cest le harl

2. stocker des fonctions dans un tableau de pointeur
{
	// creer un tableau de pointeur sur fonction et attribue les fonctions
	type(Harl::*ptrTab[])(arg) = {&Harl::debug, &Harl::info, &Harl::warning};

	// ou
	type(Harl::*ptrTab[nb])(arg);

	(this->*ptrTab[0])(arg); // pour utiliser
}

3. passer un pointeur sur fonction en paramètre
{

}


# tips
au lieu dutiliser
{ std::cout }
dans le code on peut utiliser au debut (hors fonction)
{ using std::cout; }
comme ca on peut utiliser dans le code
{ cout } tout seul

# function std::string::find
{ size_t pos = line.find(arg);
	if (pos != std::string::npos) // if i found }
npos is size_t var that is set when find cannot find




pourquoi virtual pour le destructeur et pas pour scavtrap ou claptrap?

Si une classe a des fonctions virtuelles et peut être manipulée en polymorphisme, son destructeur doit être virtual.
Animal doit avoir un destructeur virtuel, car on l'utilise via Animal*.
ClapTrap n’a pas besoin de virtual, car on ne manipule pas souvent des ClapTrap* pointant vers ScavTrap ou FragTrap.



Comment vérifier qu'il n'y a qu'une seule instance de ClapTrap dans DiamondTrap ?

Pour savoir si ClapTrap est bien instancié une seule fois, on peut :
Afficher des messages dans le constructeur de ClapTrap
Afficher l’adresse mémoire de ClapTrap dans DiamondTrap
bon cas :
ClapTrap constructor called at 0x5612a3f3b2c0  ✅ Une seule fois !
ScavTrap constructor called
FragTrap constructor called
DiamondTrap constructor called
Address of ClapTrap part in DiamondTrap: 0x5612a3f3b2c0  ✅ Même adresse !
mauvais cas :
ClapTrap constructor called at 0x5612a3f3b2c0  ❌ Première instance
ScavTrap constructor called
ClapTrap constructor called at 0x5612a3f3b300  ❌ Deuxième instance !!!
FragTrap constructor called
DiamondTrap constructor called




Où faut-il mettre virtual pour éviter le problème du diamant ?

Non, il ne faut pas écrire :

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap  // ❌ PAS ICI !

👉 Le mot-clé virtual doit être mis uniquement dans FragTrap et ScavTrap lorsqu'ils héritent de ClapTrap, pas dans DiamondTrap.

On applique virtual sur ClapTrap lorsqu'il est hérité par ScavTrap et FragTrap

Dans DiamondTrap, PAS BESOIN de virtual car ClapTrap est déjà marqué comme virtuel dans ses classes intermédiaires

Pourquoi virtual uniquement sur FragTrap et ScavTrap ?

    Cela garantit que ClapTrap n'est hérité qu'une seule fois.
    DiamondTrap reçoit une seule copie de ClapTrap, même s’il passe par FragTrap et ScavTrap.

👉 Si tu mets virtual dans DiamondTrap, ça ne sert à rien car l’héritage virtuel doit être défini au moment où on hérite directement de ClapTrap.

Que se passe-t-il dans la mémoire ?

🔹 Sans virtual → ClapTrap est dupliqué :

DiamondTrap
├── FragTrap
│   └── ClapTrap (copie 1) ❌
└── ScavTrap
    └── ClapTrap (copie 2) ❌

🔹 Avec virtual dans FragTrap et ScavTrap → Une seule instance de ClapTrap :

DiamondTrap
├── FragTrap
│  
├── ScavTrap
│  
└── ClapTrap (une seule instance) ✅


