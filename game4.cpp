#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <tuple>
#include <stack>
#include <unordered_map>

using namespace std;


void clear() {
    cout << string(50, '\n');
}


void draw(string type) {
    if (type == "Lion") {
        cout << R"(
======================================================================
                                                ,w.
                                              ,YWMMw  ,M  ,
                         _.---.._   __..---._.'MMMMMw,wMWmW,
                    _.-""        """           YP"WMMMMMMMMMb,
                 .-' __.'                   .'     MMMMW^WMMMM;
     _,        .'.-'"; `,       /`     .--""      :MMM[==MWMW^;
  ,mM^"     ,-'.'   /   ;      ;      /   ,       MMMMb_wMW"  @\
 ,MM:.    .'.-'   .'     ;     `\    ;     `,     MMMMMMMW `"=./`-,
 WMMm__,-'.'     /      _.\      F"""-+,,   ;_,_.dMMMMMMMM[,_ / `=_}
 "^MP__.-'    ,-' _.--""   `-,   ;       \  ; ;MMMMMMMMMMW^``; __|
            /   .'            ; ;         )  )`{  \ `"^W^`,   \  :
           /  .'             /  (       .'  /     Ww._     `.  `"
          /  Y,              `,  `-,=,_{   ;      MMMP`""-,  `-._.-,
         (--, )                `,_ / `) \/"")      ^"      `-, -;"\:
          `"""                    `"""   `"'                  `---"
======================================================================
        )" << endl;
    } else if (type == "Boar") {
        cout << R"(
============================================
              _,-""""-..__
         |`,-'_. `  ` ``  `--'""".
         ;  ,'  | ``  ` `  ` ```  `.
       ,-'   ..-' ` ` `` `  `` `  ` |==.
     ,'    ^    `  `    `` `  ` `.  ;   \
    `}_,-^-   _ .  ` \ `  ` __ `   ;    #
       `"---"' `-`. ` \---""`.`.  `;
                  \\` ;       ; `. `,
                   ||`;      / / | |
                  //_;`    ,_;' ,_;"
============================================
        )" << endl;
    } else if (type == "Spider") {
        cout << R"(
================================
        /\  .-"""-.  /\
       //\\/  ,,,  \//\\
       |/\| ,;;;;;, |/\|
       //\\\;-"""-;///\\
      //  \/   .   \/  \\
     (| ,-_| \ | / |_-, |)
       //`__\.-.-./__`\\
      // /.-(() ())-.\ \\
     (\ |)   '---'   (| /)
      ` (|           |) `
        \)           (/
================================
        )" << endl;
    } else if (type == "Wolf") {
        cout << R"(
=====================================
                          ,     ,
                          |\---/|
                         /  , , |
                    __.-'|  / \ /
           __ ___.-'        ._O|
        .-'  '        :      _/
       / ,    .        .     |
      :  ;    :        :   _/
      |  |   .'     __:   /
      |  :   /'----'| \  |
      \  |\  |      | /| |
       '.'| /       || \ |
       | /|.'       '.l \\_
       || ||             '-'
       '-''-'
=====================================
        )" << endl;
    } else if (type == "Elephant") {
        cout << R"(
=====================================================
              ___.-~"~-._   __....__
            .'    `    \ ~"~        ``-.
           /` _      )  `\              `\
          /`  a)    /     |               `\
         :`        /      |                 \
    <`-._|`  .-.  (      /   .            `;\\
     `-. `--'_.'-.;\___/'   .      .       | \\
  _     /:--`     |        /     /        .'  \\
 ("\   /`/        |       '     '         /    :`;
 `\'\_/`/         .\     /`~`=-.:        /     ``
   `._.'          /`\    |      `\      /(
                 /  /\   |        `Y   /  \
                J  /  Y  |         |  /`\  \
               /  |   |  |         |  |  |  |
              "---"  /___|        /___|  /__|
=====================================================
        )" << endl;
    } else if (type == "Slime") {
        cout << R"(
==================================
         , - ~ ~ ~ - ,
     , '               ' ,
   ,    !           !      ,
  ,                         ,
 ,               @@     @@   ,
 , !             @@     @@   ,
 ,        !                  ,
  ,                         ,
   ,                    !  ,
     ,       !          , '
       ' - , _ _ _ ,  '
==================================
        )" << endl;
    }
}

// Displays the abilities
pair<string, int> getability(string pclass, int mana, int inte, int level) {
    string input;
    string ability;
    int cost;
    cout << "Choose an ability" << endl;
    if (pclass == "Champion") { // Champion Section
        cost = inte*(level);
        cout << "[1] Cleaving Strike [" << cost << " mana]" << endl;
        cout << "[2] Melting Thrust [" << cost << " mana]" << endl;
        cout << "[3] Critical Bash [" << cost << " mana]" << endl;
        cost = inte*(level+1);
        cout << "[4] Purify [" << cost << " mana]" << endl;
        cost = inte*(level);
        cin >> input;
        if (input == "1") {
            ability = "cleaving strike";
            if (mana >= cost) {
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else if (input == "2") {
            ability = "melting thrust";
            if (mana >= cost) {
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else if (input == "3") {
            ability = "critical bash";
            if (mana >= cost) {
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else if (input == "4") {
            ability = "purify";
            if (mana >= cost) {
                cost = inte*(level+1);
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else {
            ability = "none";
            return {ability, mana};
        }
    } else if (pclass == "Necromancer") { // Necromancer Section
        cost = inte*(level);
        cout << "[1] Shadow Strike [" << cost << " mana]" << endl;
        cout << "[2] Cripple [" << cost << " mana]" << endl;
        cout << "[3] Mutilate [" << cost << " mana]" << endl;
        cost = inte*(level+2);
        cout << "[4] Life Tap [" << cost << " mana]" << endl;
        cost = inte*(level);
        cin >> input;
        if (input == "1") {
            ability = "shadow strike";
            if (mana >= cost) {
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else if (input == "2") {
            ability = "cripple";
            if (mana >= cost) {
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else if (input == "3") {
            ability = "mutilate";
            if (mana >= cost) {
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else if (input == "4") {
            ability = "life tap";
            if (mana >= cost) {
                cost = inte*(level+2);
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else {
            ability = "none";
            return {ability, mana};
        }
    } else if (pclass == "Assassin") { // Assassin Section
        cost = inte*(level);
        cout << "[1] Back Stab [" << cost << " mana]" << endl;
        cout << "[2] Headcrack [" << cost << " mana]" << endl;
        cout << "[3] Poison [" << cost << " mana]" << endl;
        cost = inte*10;
        cout << "[4] Assassinate [" << cost << " mana]" << endl;
        cost = inte*(level);
        cin >> input;
        if (input == "1") {
            ability = "back stab";
            if (mana >= cost) {
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else if (input == "2") {
            ability = "headcrack";
            if (mana >= cost) {
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else if (input == "3") {
            ability = "poison";
            if (mana >= cost) {
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else if (input == "4") {
            ability = "assassinate";
            if (mana >= cost) {
                cost = inte*10;
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else {
            ability = "none";
            return {ability, mana};
        }
    }else if (pclass == "Cleric") { // Cleric Section
        cost = inte*(level);
        cout << "[1] Smite [" << cost << " mana]" << endl;
        cout << "[2] Enflame [" << cost << " mana]" << endl;
        cout << "[3] Atonement [" << cost << " mana]" << endl;
        cout << "[4] Flash Heal [" << cost << " mana]" << endl;
        cin >> input;
        if (input == "1") {
            ability = "smite";
            if (mana >= cost) {
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else if (input == "2") {
            ability = "enflame";
            if (mana >= cost) {
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else if (input == "3") {
            ability = "atonement";
            if (mana >= cost) {
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else if (input == "4") {
            ability = "flash heal";
            if (mana >= cost) {
                mana = mana - cost;
                return {ability, mana};
            } else {
                ability = "none";
                return {ability, mana};
            }
        } else {
            ability = "none";
            return {ability, mana};
        }
    } else {
        ability = "none";
        return {ability, mana};
    }

    }


struct Node {
    string character;
    int xp;
    int gold;
    Node* left;
    Node* right;
};

Node* createNode(string character, int xp, int gold) {
    Node* newNode = new Node;
    newNode->character = character;
    newNode->xp = xp;
    newNode->gold = gold;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, string character, int xp, int gold) {
    if (root == nullptr) {
        return createNode(character, xp, gold);
    }

    if (xp < root->xp) {
        root->left = insert(root->left, character, xp, gold);
    } else {
        root->right = insert(root->right, character, xp, gold);
    }

    return root;
}

void displayInOrder(Node* root) {
    if (root != nullptr) {
        displayInOrder(root->left);
        cout << root->character << " - " << root->xp << " xp\t" << root->gold << " gold" << endl;
        displayInOrder(root->right);
    }
}

void displayStack(stack<pair<string, int>>& s) {
    while (!s.empty()) {
        cout << s.top().first << " " << s.top().second << endl;
        s.pop();
    }
}

class ClassHeap {
private:
    std::unordered_map<int, string> classOptions;

public:
    ClassHeap() {
        classOptions[1] = "Champion";
        classOptions[2] = "Necromancer";
        classOptions[3] = "Assassin";
        classOptions[4] = "Cleric";
    }

    std::string getClass(int choice) {
        auto it = classOptions.find(choice);
        if (it != classOptions.end()) {
            return it->second;
        }
        return "Invalid Class";
    }
};



int main()
{

    srand((unsigned)time(0));
    string code;
    string name;
    string etype;
    string pclass;
    string action;
    string status = "arena";
    int ckills; // Current amount of kills in Dungeon
    int rkills;
    int bhp = 0; // Bonus hp
    double bphp = 0;
    double goldb = 0; // Bonus Gold
    int slimychestplate = 0;
    int slimyhelmet = 0;
    int oozinglegplates = 0;
    int oozingboots = 0;
    string head = "Open"; // Whats on the head
    string chest = "Open"; // Whats on the chest
    string legs = "Open"; // Whats on the legs
    string feet = "Open";  // Player Variables
    int piclass = 0;
    int level = 1; // Level
    int xp = 0; // Current XP
    int rxp;
    int xpb = 50;
    int xpl = 25;
    int stre = 5;
    int inte = 5;
    int dext = 5;
    int skill = 0;
    int dmg;
    int hp = stre * 20;
    int mhp = stre * 20; // Max hp
    int shp = stre * 20; // hp used to set enemy hp
    int mana = inte * 10; // Mana
    int mmana = inte * 10; // Max Mana
    int hpotion = 1; // Healing Potions
    int price; // Price of item(s)
    int gold = 25; // Gold
    int rgold; // Reward Gold
    int x = 0;
    int y = 0;
    string sslimychestplate = std::to_string(slimychestplate);
    string sslimyhelmet = std::to_string(slimyhelmet);
    string soozinglegplates = std::to_string(oozinglegplates);
    string soozingboots = std::to_string(oozingboots);
    string spiclass = std::to_string(piclass);
    string slevel = std::to_string(level);
    string sxp = std::to_string(xp);
    string sxpb = std::to_string(xpb);
    string sxpl = std::to_string(xpl);
    string sstre = std::to_string(stre);
    string sinte = std::to_string(inte);
    string sdext = std::to_string(dext);
    string shpotion = std::to_string(hpotion);
    string sgold = std::to_string(gold);
    string sskill = std::to_string(skill);

    int quest = 0;
    int questr = 0;
    int questc = 0;
    int questreward = 0;
    string questmob; // Enemy that must be slain to complete the quest
    string questdisplay; // Displays the quest
    int qxpr;
    int qgoldr;
    int elevel;
    int ehp;
    int mehp;
    int edmg;
    string eability;
    int random;
    int random2;
    string input;

    neworload:
    clear();

    cout<<"The Charecters of the GAME : "<<endl;
    Node* root = nullptr;
    root = insert(root, "Champion", 10, 5);
    root = insert(root, "Necromencer", 5, 3);
    root = insert(root, "Assassin", 7, 2);
    root = insert(root, "Cleric", 2, 0);

    cout << "Characters sorted by XP:" << endl;
    displayInOrder(root);
    cout<<endl;
    cout<<endl;

    cout<< "VILLAINS"<<endl;
    cout<<"=========================================="<<endl<<endl;
    stack<pair<string, int>> characters;

    characters.push(make_pair("lion", 103));
    characters.push(make_pair("spider", 101));
    characters.push(make_pair("wolf", 97));
    characters.push(make_pair("elephant", 102));
    characters.push(make_pair("boar", 105));

    cout << "Characters in reverse order:" << endl;
    displayStack(characters);
    cout<<endl<<endl;
    cout << "Hello there please choose an option" << endl;
    cout<< endl<< endl;
    cout << "1- New Game" << endl;
    cout << "2- Load Game" << endl;
    cin >> input;

    if (input == "1") {

        goto setup;
    } else if (input == "2") {
        goto loadgame;
    } else {
        goto neworload;
    }

    setup:
    clear();
    cout << "Hello there, what is your name?" << endl;
    cin >> input;
    name = input;
    cout << "Ahh, is it " << input << "? [y/n]" << endl;
    cin >> input;
    if (input == "n") {
        clear();
        goto setup;
    }

    // Class Setup
    csetup:
    cout << endl;
    cout << "Choose your Class" << endl;
    cout << "=================" << endl;
    cout << "[1] Champion" << endl;
    cout << "[2] Necromancer" << endl;
    cout << "[3] Assassin" << endl;
    cout << "[4] Cleric" << endl;
    cin >> input;

    if (input == "1") {
        pclass = "Champion";
        piclass = 1;
    } else if (input == "2") {
        pclass = "Necromancer";
        piclass = 2;
    } else if (input == "3") {
        pclass = "Assassin";
        piclass = 3;
    } else if (input == "4") {
        pclass = "Cleric";
        piclass =4;
    }

    goto menue;

    // Main Menue
    menue:
    clear();

    if (pclass == "Assassin") {
        goldb = 1.25;
    } else {
        goldb = 1;
    }

    cout << R"(
___  ___ _____ _   _ _   _
|  \/  ||  ___| \ | | | | |
| .  . || |__ |  \| | | | |
| |\/| ||  __|| . ` | | | |
| |  | || |___| |\  | |_| |
\_|  |_/\____/\_| \_/\___/
    )" << endl;

    cout << pclass << " " << name << endl;
    cout << "[1] Traveller's Encounter" << endl;
    cout << "[2] Inventory" << endl;
    cout << "[3] Rest (Returns you to full health/mana)" << endl;
    cout << "[4] Assign Skillpoints [" << skill << " available]" << endl;
    cout << "[5] Shop" << endl;
    cout << "[6] Questhall" << endl;
    cout << "[7] Dungeons" << endl;
    cout << "[98] Save Game" << endl;
    cout << "[99] Exit" << endl;
    cin >> input;
    if (input == "1") {
        goto sarena;
    } else if (input == "99") {
        goto leave;
    } else if (input == "2") {
        goto inventory;
    } else if (input == "3") {
        mhp = stre * 20;
        mmana = inte * 10;
        hp = mhp;
        hp = hp * (bphp+1);
        hp = hp + bhp;
        mana = mmana;
        goto menue;
    } else if (input == "4") {
        goto askill;
    } else if (input == "5") {
        goto shop;
    } else if (input == "6") {
        goto questhall;
    } else if (input == "7") {
        goto dungeonmenue;
    } else if (input == "98") {
        goto savegame;
    }

    goto menue;

    // Setting Up Enemys
    sarena:

    mmana = inte * 10;
    shp = stre * 20;
    mhp = stre * 20;
    random = rand()%5+1;
    switch (random) {
        case 1:
            etype = "Lion";
            random2 = rand()%2+1;
            eability = "gnaw";
            if (random2 == 1) {
                ehp = shp + rand()%(level*5);
            } else {
                ehp = shp - rand()%(level*5);
            }
            mehp = ehp;
        break;

        case 2:
            etype = "Boar";
            random2 = rand()%2+1;
            eability = "goar";
            if (random2 == 1) {
                ehp = shp + rand()%(level*3);
            } else {
                ehp = shp - rand()%(level*3);
            }
            mehp = ehp;
        break;

        case 3:
            etype = "Spider";
            random2 = rand()%2+1;
            eability = "webspin";
            elevel = rand()%(level+3)+1;
            if (random2 == 1) {
                ehp = shp + rand()%(level*2);
            } else {
                ehp = shp - rand()%(level*2);
            }
            mehp = ehp;
        break;

        case 4:
            etype = "Wolf";
            random2 = rand()%2+1;
            eability = "growl";
            elevel = rand()%(level+3)+1;
            if (random2 == 1) {
                ehp = shp + rand()%(level*4);
            } else {
                ehp = shp - rand()%(level*4);
            }
            mehp = ehp;
        break;

        case 5:
            etype = "Elephant";
            random2 = rand()%2+1;
            eability = "stomp";
            if (random2 == 1) {
                ehp = shp + rand()%(level*6);
            } else {
                ehp = shp - rand()%(level*3);
            }
            mehp = ehp;
        break;

    }

    elevel = rand()%(level+3)+1;
    if ((elevel < (level-3)) || (elevel > (level+3))) {
        elevel = level;
    }

    goto aarena;

    // Arena Main
    aarena:

    clear();
    draw(etype);
    cout << "[" << etype << " " << elevel << "] >>> " << ehp << "/" << mehp << endl;
    cout << "[" << name << " " << level << "] >>> " << hp << "/" << mhp << endl;
    cout << "-Mana- >>> " << mana << "/" << mmana << endl;
    cout << "[1] Attack" << endl;
    cout << "[2] Do ability" << endl;
    cout << "[3] Inventory" << endl;
    cout << "[99] Flee" << endl;
    cin >> input;

    if (input == "1") {
        dmg = (stre+inte) + rand()%(dext*2);
        ehp = ehp - dmg;
        // If enemy ehp < 0 then
        if (ehp <= 0) {
            clear();
            cout << "[*] You killed the " << etype << endl;
            cout << "Type [1] to continue" << endl;
            cin >> input;
            goto rarena;
        }
        random2 = rand()%2+1;
        edmg = dmg;
        // Setting up enemy damage
        if (random2 == 1) {
                edmg = edmg + rand()%(dext*2);
            } else {
                edmg = edmg - rand()%(dext*2);
            }
        hp = hp - edmg;
        // If player hp < 0 then
        if (hp <= 0) {
            clear();
            cout << "[*] You Died" << endl;
            cout << "Type [1] to continue" << endl;
            cin >> input;
            if (status != "arena") {
                status = "arena";
            }
            goto menue;
        }
        goto aarena;
    } else if (input == "99") {
        goto menue;
    } else if (input == "2") {
        goto darena;
    } else if (input == "3") {
        goto iarena;
    } else {
        goto aarena;
    }

    // Using items from Inventory
    iarena:
    clear();

    cout << "Inventory" << endl;
    cout << "[1] Health Potion, " << hpotion << " (Heals you to max health)" << endl;
    cout << "[99] Exit" << endl;
    cin >> input;
    if (input == "1") {
        if (hpotion > 0) {
            hpotion = hpotion - 1;
            hp = mhp;
        }
    } else if (input == "99") {
        goto aarena;
    }
    goto iarena;

    // Picking spells and doing damage
    darena:

    clear();
    tie(action, mana) = getability(pclass, mana, inte, level);
    // Champion spells
    if (action == "cleaving strike") {
        dmg = (stre+inte+dext) + rand()%(dext*2);
    } else if (action == "melting thrust") {
        dmg = (stre+inte+dext) + rand()%(stre*2);
    } else if (action == "critical bash") {
        dmg = (stre+inte+dext) + rand()%(inte*2);
    } else if (action == "purify") {
        hp = hp + inte*(level)+(rand()%inte);
        if (hp > mhp) {
            hp = mhp;
        }
        goto aarena;
    } else if (action == "none") {
        goto aarena;
    } else if (action == "shadow strike") {
        dmg = (stre+inte+dext) + rand()%(dext*2);
    } else if (action == "cripple") {
        dmg = (stre+inte+dext) + rand()%(stre*2);
    } else if (action == "mutilate") {
        dmg = (stre+inte+dext) + rand()%(inte*2);
    } else if (action == "life tap") {
        dmg = (stre+inte) + rand()%(inte);
        hp = hp + dmg;
        if (hp > mhp) {
            hp = mhp;
        }
        ehp = ehp - dmg;
        // If enemy ehp < 0 then
        if (ehp <= 0) {
            clear();
            cout << "[*] You killed the " << etype << endl;
            cout << "Type [1] to continue" << endl;
            cin >> input;
            goto rarena;
        }
        goto aarena;
    }  else if (action == "back stab") {
        dmg = (stre+inte+dext) + rand()%(dext*2);
    } else if (action == "headcrack") {
        dmg = (stre+inte+dext) + rand()%(stre*2);
    } else if (action == "poison") {
        dmg = (stre+inte+dext) + rand()%(inte*2);
    } else if (action == "assassinate") {
        dmg = (stre+inte+dext) + rand()%((inte+stre)*3);
        ehp = ehp - dmg;
        // If enemy ehp < 0 then
        if (ehp <= 0) {
            clear();
            cout << "[*] You killed the " << etype << endl;
            cout << "Type [1] to continue" << endl;
            cin >> input;
            goto rarena;
        }
        goto aarena;
    } else if (action == "smite") {
        dmg = (stre+inte+dext) + rand()%(dext);
    } else if (action == "enflame") {
        dmg = (stre+inte+dext) + rand()%(stre);
    } else if (action == "atonement") {
        dmg = (stre+inte+dext) + rand()%(inte);
    } else if (action == "flash heal") {
        hp = hp + ((stre * level) + (rand()%(inte*2)));
        if (hp > mhp) {
            hp = mhp;
        }
        goto aarena;
    }

    ehp = ehp - dmg;

    if (ehp <= 0) {
        clear();
        cout << "[*] You killed the " << etype << endl;
        cout << "Type [1] to continue" << endl;
        cin >> input;
        goto rarena;
    }
    random2 = rand()%2+1;
    dmg = (stre+inte) + rand()%(dext*2);
    edmg = dmg;
    // Setting up enemy damage
    if (random2 == 1) {
        edmg = edmg + rand()%(dext*2);
    } else {
        edmg = edmg - rand()%(dext*2);
    }
    hp = hp - edmg;
    // If player hp < 0 then
    if (hp <= 0) {
        clear();
        cout << "[*] You Died" << endl;
        cout << "Type [1] to continue" << endl;
        cin >> input;
        if (status != "arena") {
            status = "arena";
        }
        goto menue;
    }
    goto aarena;


    rarena:
    clear();
    rxp = rand()%(level*2)+5;
    rgold = rand()%(level*5);
    rgold = rgold * goldb;

    cout << R"(
*******************************************************************************
          |                   |                  |                     |
 _________|________________.=""_;=.______________|_____________________|_______
|                   |  ,-"_,=""     `"=.|                  |
|___________________|__"=._o`"-._        `"=.______________|___________________
          |                `"=._o`"=._      _`"=._                     |
 _________|_____________________:=._o "=._."_.-="'"=.__________________|_______
|                   |    __.--" , ; `"=._o." ,-"""-._ ".   |
|___________________|_._"  ,. .` ` `` ,  `"-._"-._   ". '__|___________________
          |           |o`"=._` , "` `; .". ,  "-._"-._; ;              |
 _________|___________| ;`-.o`"=._; ." ` '`."\` . "-._ /_______________|_______
|                   | |o;    `"-.o`"=._``  '` " ,__.--o;   |
|___________________|_| ;     (#) `-.o `"=.`_.--"_o.-; ;___|___________________
____/______/______/___|o;._    "      `".o|o_.--"    ;o;____/______/______/____
/______/______/______/_"=._o--._        ; | ;        ; ;/______/______/______/_
____/______/______/______/__"=._o--._   ;o|o;     _._;o;____/______/______/____
/______/______/______/______/____"=._o._; | ;_.--"o.--"_/______/______/______/_
____/______/______/______/______/_____"=.o|o_.--""___/______/______/______/____
/______/______/______/______/______/______/______/______/______/______/______/_
*******************************************************************************
    )" << endl; // That chest looks amazing

    if (status == "oozeworks") {
        goto oozeworksr;
    } else {
        goto rrarena;
    }

    rrarena:
    cout << "You recieved " << rxp << " xp" << endl;
    cout << "You recieved " << rgold << " gold" << endl;
    xp = xp + rxp;
    gold = gold + rgold;
    if (xp >= xpl) {
        level = level + 1;
        xpl = xpl + xpb;
        xpb = xpb + 50;
        skill = skill + 5;
        cout << "You have leveled up to level " << level << endl;
    }
    cout << "Type [1] to continue to the menue" << endl;

    if (etype == questmob) {
        questc = questc + 1;
    }

    cin >> input;
    goto menue;

    // Inventory
    inventory:
    clear();

    cout << R"(
       ___
       )_(                                            _
       | |                                           [_ ]
     .-'-'-.       _                               .-'. '-.
    /-::_..-\    _[_]_                            /:;/ _.-'\
    )_     _(   /_   _\      [-]                  |:._   .-|
    |;::    |   )_``'_(    .-'-'-.       (-)      |:._     |
    |;::    |   |;:   |    :-...-:     .-'-'-.    |:._     |
    |;::    |   |;:   |    |;:   |     |-...-|    |:._     |
    |;::-.._|   |;:.._|    |;:.._|     |;:.._|    |:._     |
    `-.._..-'   `-...-'    `-...-'     `-...-'    `-.____.-'
    )" << endl;

    levelalert:
    if (xp >= xpl) {
        level = level + 1;
        xpl = xpl + xpb;
        xpb = xpb + 50;
        skill = skill + 5;
        goto levelalert;
    } else {
        goto inventory2;
    }

    inventory2:
    cout << "[Level] >>> " << level << endl;
    cout << "[XP] >>> " << xp << "/" << xpl << endl;
    cout << "[Gold] >>> " << gold << endl;
    cout << "[Healing Potions] >>> " << hpotion << endl;
    cout << "==================================" << endl;
    cout << "Head- " << head << endl;
    cout << "Chest- " << chest << endl;
    cout << "Legs- " << legs << endl;
    cout << "Feet- " << feet << endl;
    cout << "==================================" << endl;
    cout << "1- Armory" << endl;
    cout << "99- Exit" << endl;
    cin >> input;
    if (input == "99") {
        goto menue;
    } else if (input == "1") {
        goto armory;
    }
    goto inventory;

    armory:
    clear();

    cout << R"(
   ,   A           {}
  / \, | ,        .--.
 |    =|= >      /.--.\
  \ /` | `       |====|
   `   |         |`::`|
       |     .-;`\..../`;_.-^-._
      /\\/  /  |...::..|`   :   `|
      |:'\ |   /'''::''|   .:.   |
       \ /\;-,/\   ::  |..:::::..|
       |\ <` >  >._::_.| ':::::' |
       | `""`  /   ^^  |   ':'   |
    )" << endl;

    cout << "1- Slimy Chestplate >>> [10% HP Increase] ";
    if (slimychestplate == 1) {
        cout << ">>> [Owned] ";
        if (chest == "slimychestplate") {
            cout << ">>> [Equiped]" << endl;
        } else {
            cout << endl;
        }
    } else {
        cout << endl;
    }

    cout << "2- Slimy Helmet >>> [5% HP Increase] ";
    if (slimyhelmet == 1) {
        cout << ">>> [Owned] ";
        if (head == "slimyhelmet") {
            cout << ">>> [Equiped]" << endl;
        } else {
            cout << endl;
        }
    } else {
        cout << endl;
    }

    cout << "3- Oozing Legplates >>> [15% HP Increase] ";
    if (oozinglegplates == 1) {
        cout << ">>> [Owned] ";
        if (legs == "oozinglegplates") {
            cout << ">>> [Equiped]" << endl;
        } else {
            cout << endl;
        }
    } else {
        cout << endl;
    }

    cout << "4- Oozing Boots >>> [10% HP Increase] ";
    if (oozingboots == 1) {
        cout << ">>> [Owned] ";
        if (feet == "oozingboots") {
            cout << ">>> [Equiped]" << endl;
        } else {
            cout << endl;
        }
    } else {
        cout << endl;
    }

    cout << "99- Back" << endl;
    cin >> input;
    if (input == "99") {
        goto armor2;
    } else if (input == "1") {
        if (chest == "slimychestplate") {
            chest = "Open";
            goto armory;
        } else if (slimychestplate == 1) {
            chest = "slimychestplate";
            goto armory;
        } else {
            goto armory;
        }
    } else if (input == "2") {
        if (head == "slimyhelmet") {
            head = "Open";
            goto armory;
        } else if (slimyhelmet == 1) {
            head = "slimyhelmet";
            goto armory;
        } else {
            goto armory;
        }
    } else if (input == "3") {
        if (legs == "oozinglegplates") {
            legs = "Open";
            goto armory;
        } else if (oozinglegplates == 1) {
            legs = "oozinglegplates";
            goto armory;
        } else {
            goto armory;
        }
    } else if (input == "4") {
        if (feet == "oozingboots") {
            feet = "Open";
            goto armory;
        } else if (oozingboots == 1) {
            feet = "oozingboots";
            goto armory;
        } else {
            goto armory;
        }
    }

    armor2:
    bhp = 0;
    bphp = 0;
    // Head
    if (head == "slimyhelmet") {
        bphp = bphp + .10;
    }
    // Chest
    if (chest == "slimychestplate") {
        bphp = bphp + .05;
    }
    // Legs
    if (legs == "oozinglegplates") {
        bphp = bphp + .15;
    }
    // Feet
    if (feet == "oozingboots") {
        bphp = bphp + .10;
    }
    goto inventory;

    askill:
    clear();

    cout << R"(
              .__=\__                  .__==__,
            jf'      ~~=\,         _=/~'      `\,
        ._jZ'            `\q,   /=~             `\__
       j5(/                 `\./                  V\\,
     .Z))' _____              |             .____, \)/\
    j5(K=~~     ~~~~\=_,      |      _/=~~~~'    `~~+K\\,
  .Z)\/                `~=L   |  _=/~                 t\ZL
 j5(_/.__/===========\__   ~q |j/   .__============___/\J(N,
4L#XXXL_________________XGm, \P  .mXL_________________JXXXW8L
~~~~~~~~~~~~~~~~~~~~~~~~~YKWmmWmmW@~~~~~~~~~~~~~~~~~~~~~~~~~~
    )" << endl; // Bedtime stories?

    cout << "Available Skillpoints [" << skill << "]" << endl;
    cout << "1- Strength [" << stre << "]" << endl;
    cout << "2- Intelligence [" << inte << "]" << endl;
    cout << "3- Dexterity [" << dext << "]" << endl;
    cout << "99- Exit" << endl;
    cin >> input;
    if (skill > 0) {
        if (input == "1") {
            stre = stre + 1;
            skill = skill - 1;
        } else if (input == "2") {
            inte = inte + 1;
            skill = skill - 1;
        } else if (input == "3") {
            dext = dext + 1;
            skill = skill - 1;
        } else if (input == "99") {
            goto menue;
        }
    } else {
        goto menue;
    }
    goto askill;

    shop:
    clear();

    cout << R"(
                               ____
                  _           |---||            _
                  ||__________|---||___________||
                 /_ _ _ _ _ _ |:._|'_ _ _ _ _ _ _\`.
                /_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\:`.
               /_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\::`.
              /:.___________________________________\:::`-._
          _.-'_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _`::::::`-.._
      _.-' _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ `:::::::::`-._
    ,'_:._________________________________________________`:_.::::-';`
     `.'/ || |:::::`.'/::::::::`.'/::::::::`.'/::::::|.`.'/.|     :|
      ||  || |::::::||::::::::::||::::::::::||:::::::|..||..|     ||
      ||  || |  __  || ::  ___  || ::  __   || ::    |..||;||     ||
      ||  || | |::| || :: |:::| || :: |::|  || ::    |.|||:||_____||__
      ||  || | |::| || :: |:::| || :: |::|  || ::    |.|||:||_|_|_||,(
      ||_.|| | |::| || :: |:::| || :: |::|  || ::    |.'||..|    _||,|
   .-'::_.:'.:-.--.-::--.-:.--:-::--.--.--.-::--.--.-:.-::,'.--.'_|| |
    );||_|__||_|__|_||__|_||::|_||__|__|__|_||__|__|_|;-'|__|_(,' || '-
    ||||  || |. . . ||. . . . . ||. . . . . ||. . . .|::||;''||   ||:'
    ||||.;  _|._._._||._._._._._||._._._._._||._._._.|:'||,, ||,,
    '''''           ''-         ''-         ''-         '''  '''
    )" << endl;

    price = level*5;
    cout << "[Gold] >>> " << gold << endl;
    cout << "1- Health Potion (" << price << " gold)" << endl;
    cout << "99- Exit" << endl;
    cin >> input;
    if (input == "1") {
        price = level*5;
        if (gold >= price) {
            hpotion = hpotion + 1;
            gold = gold - price;
            goto shop;
        } else {
            goto menue;
        }
    } else if (input == "99") {
        goto menue;
    }
    goto shop;

    // Receive / "Turn" in quests
    questhall:
    clear();

    cout << R"(
         _______________
    ()==(              (@==()
         '______________'|
           |             |
           |             |
         __)_____________|
    ()==(               (@==()
         '--------------'
    )" << endl;

    cout << "Current Quest >>> ";

    if (quest == 0) {
        quest = rand()%5+1;
        switch (quest) {
            case 1:
                questc = 0;
                questr = 6;
                questmob = "Boar";
                questreward = rand()%4+1;
                questdisplay = "Slay Boars";
            break;

            case 2:
                questc = 0;
                questr = 6;
                questmob = "Lion";
                questreward = rand()%4+1;
                questdisplay = "Slay Lions";
            break;

            case 3:
                questc = 0;
                questr = 6;
                questmob = "Elephant";
                questreward = rand()%4+1;
                questdisplay = "Slay Elephants";
            break;

            case 4:
                questc = 0;
                questr = 6;
                questmob = "Wolf";
                questreward = rand()%4+1;
                questdisplay = "Slay Wolves";
            break;

            case 5:
                questc = 0;
                questr = 6;
                questmob = "Spider";
                questreward = rand()%4+1;
                questdisplay = "Slay Spiders";
            break;

        }
    }

    cout << questdisplay << " [" << questc << "/" << questr << "]" << endl;
    cout << "Reward >>> ";

    switch (questreward) {
        case 1:
            qgoldr = rand()%(level*10)+(level*10);
            cout << qgoldr << " Gold" << endl;
        break;

        case 2:
            qxpr = rand()%(level*5)+(level*5);
            cout << qxpr << " XP" << endl;
        break;

        case 3:
            cout << "Slimy Chestplate >>> [10% HP Increase]" << endl;
        break;

        case 4:
            cout << "Slimy Helmet >>> [5% HP Increase]" << endl;
        break;
    }

    if (questc >= questr) {
        quest = 0;
        switch (questreward) {
            case 1:
                gold = gold + qgoldr;
                goto questhall;
            break;

            case 2:
                xp = xp + qxpr;
                goto questhall;
            break;

            case 3:
                slimychestplate = 1;
                goto questhall;
            break;

            case 4:
                slimyhelmet = 1;
                goto questhall;
            break;
        }
    }

    cout << "99- Exit" << endl;
    cin >> input;
    goto menue;

    dungeonmenue:
        clear();
    cout << R"(
   _________________________________________________________
  |                            ,                            |
  |      .-'````````'.        '(`        .-'```````'-.      |
  |    .` |           `.      `)'      .` |           `.    |
  |   /   |   ()        \      U      /   |    ()       \   |
  |  |    |    ;         | o   T   o |    |    ;         |  |
  |  |    |     ;        |  .  |  .  |    |    ;         |  |
  |  |    |     ;        |   . | .   |    |    ;         |  |
  |  |    |     ;        |    .|.    |    |    ;         |  |
  |  |    |____;_________|     |     |    |____;_________|  |
  |  |   /  __ ;   -     |     !     |   /     `'() _ -  |  |
  |  |  / __  ()        -|        -  |  /  __--      -   |  |
  |  | /        __-- _   |   _- _ -  | /        __--_    |  |
  |__|/__________________|___________|/__________________|__|
 /                                             _ -        lc \
/   -_- _ -             _- _---                       -_-  -_ \

    )" << endl;

    cout << "Available Dungeons" << endl;
    cout << "[1] Oozing Oozeworks >>> [150 Gold, Oozing Gear]" << endl;
    cout << "[99] Return to Menue" << endl;
    cin >> input;
    if (input == "99") {
        goto menue;
    } else if (input == "1") {
        if (gold >= 150) {
            status = "oozeworks";
            gold = gold - 150;
            ckills = 0;
            rkills = 6;
            goto oozeworks;
        } else {
            goto menue;
        }
    }
    goto dungeonmenue;

    oozeworks:
    clear();
    cout << R"(
 _____          _               _____                              _
|  _  |        (_)             |  _  |                            | |
| | | | ___ _____ _ __   __ _  | | | | ___ ______      _____  _ __| | _____
| | | |/ _ \_  / | '_ \ / _` | | | | |/ _ \_  /\ \ /\ / / _ \| '__| |/ / __|
\ \_/ / (_) / /| | | | | (_| | \ \_/ / (_) / /  \ V  V / (_) | |  |   <\__ \
 \___/ \___/___|_|_| |_|\__, |  \___/ \___/___|  \_/\_/ \___/|_|  |_|\_\___/
                         __/ |
                        |___/
    )" << endl;

    if (ckills >= rkills) {
        goto oozeworksc;
    }

    cout << "[1] Continue [" << ckills << "/" << rkills << " slimes killed]" << endl;
    cout << "[2] Adrenalin (Heals all missing hp/mana)" << endl;
    cout << "[99] Exit" << endl;
    cin >> input;
    if (input == "1") {
        mmana = inte * 10;
        shp = stre * 20;
        mhp = stre * 20;
        etype = "Slime";
        random2 = rand()%2+1;
        eability = "ooze";
        if (random2 == 1) {
            ehp = shp + rand()%(level*8);
        } else {
            ehp = shp + rand()%(level*6);
        }
        mehp = ehp;
        elevel = rand()%(level+3)+1;
        if ((elevel < (level-3)) || (elevel > (level+3))) {
            elevel = level;
        }
        goto aarena;
    } else if (input == "99") {
        goto menue;
    } else if (input == "2") {
        mhp = stre * 20;
        mmana = inte * 10;
        hp = mhp;
        hp = hp * (bphp+1);
        hp = hp + bhp;
        mana = mmana;
    }
    goto oozeworks;

    oozeworksc:
    status = "arena";
    cout << "You have completed the Oozing Oozworks" << endl;
    rxp = rand()%(level*6)+5;
    rgold = rand()%(level*9);
    cout << "You recieved " << rxp << " xp" << endl;
    cout << "You recieved " << rgold << " gold" << endl;
    xp = xp + rxp;
    gold = gold + rgold;
    random = rand()%2+1;
    switch (random) {
        case 1:
            cout << "New legplates unlocked! >>> [Oozing Legplates, increases hp by 15%]" << endl;
            oozinglegplates = 1;
        break;

        case 2:
            cout << "New boots unclocked! >>> [Oozing Boots, increases hp by 10%]" << endl;
            oozingboots = 1;
        break;
    }
    cout << "Type [1] to return to the menue" << endl;
    cin >> input;
    goto menue;

    oozeworksr:
    ckills = ckills + 1;
    rxp = rand()%(level*4)+5;
    rgold = rand()%(level*7);
    rgold = rgold * goldb;
    cout << "You recieved " << rxp << " xp" << endl;
    cout << "You recieved " << rgold << " gold" << endl;
    xp = xp + rxp;
    gold = gold + rgold;
    if (xp >= xpl) {
        level = level + 1;
        xpl = xpl + xpb;
        xpb = xpb + 50;
        skill = skill + 5;
        cout << "You have leveled up to level " << level << endl;
    }
    cout << "Type [1] to continue your adventure" << endl;
    cin >> input;
    goto oozeworks;

    savegame:
    clear();

    // Saving / Loading Strings
    sslimychestplate = std::to_string(slimychestplate);
    sslimyhelmet = std::to_string(slimyhelmet);
    soozinglegplates = std::to_string(oozinglegplates);
    soozingboots = std::to_string(oozingboots);
    spiclass = std::to_string(piclass);
    slevel = std::to_string(level);
    sxp = std::to_string(xp);
    sxpb = std::to_string(xpb);
    sxpl = std::to_string(xpl);
    sstre = std::to_string(stre);
    sinte = std::to_string(inte);
    sdext = std::to_string(dext);
    shpotion = std::to_string(hpotion);
    sgold = std::to_string(gold);
    sskill = std::to_string(skill);

    code = "";
    code = code + sgold + ":" + sstre + ":" + sinte + ":" + sdext + ":" + sskill + ":" + sxp + ":" + sxpl + ":" + sxpb + ":" + slevel + ":";
    code = code + shpotion + ":";
    code = code + spiclass + sslimyhelmet + sslimychestplate + soozinglegplates + soozingboots;
    cout << code << endl;
    cout << "Type [1] to return to the menue" << endl;
    cin >> input;
    goto menue;

    // Loading the game code they input
    loadgame:
    clear();

    sslimychestplate = "";
    sslimyhelmet = "";
    soozinglegplates = "";
    soozingboots = "";
    spiclass = "";
    slevel = "";
    sxp = "";
    sxpb = "";
    sxpl = "";
    sstre = "";
    sinte = "";
    sdext = "";
    shpotion = "";
    sgold = "";
    sskill = "";

    cout << "Please input your game code EXACTLY (if you don't this may corrupt your game save)" << endl;
    cin >> input;
    code = input;
    goto compile;
    cout << code << endl;

    // Loading Game Save FILE
    compile:
    x = 0;
    goldr:
    cout << sgold << endl;
    if (code[x] == ':') { // If the character is a pipe
        x=x+1; // Go to next variable
        goto strer;
    } else {
        sgold = sgold + code[x]; // If not add the variables
        x=x+1; // Go to next charcter
        goto goldr;
    }
    strer:
    if (code[x] == ':') { // If the character is a pipe
        x=x+1; // Go to next variable
        goto inter;
    } else {
        sstre = sstre + code[x]; // If not add the variables
        x=x+1; // Go to next charcter
        goto strer;
    }
    inter:
    if (code[x] == ':') { // If the character is a pipe
        x=x+1; // Go to next variable
        goto dextr;
    } else {
        sinte = sinte + code[x]; // If not add the variables
        x=x+1; // Go to next charcter
        goto inter;
    }
    dextr:
    if (code[x] == ':') { // If the character is a pipe
        x=x+1; // Go to next variable
        goto skillr;
    } else {
        sdext = sdext + code[x]; // If not add the variables
        x=x+1; // Go to next charcter
        goto dextr;
    }
    skillr:
    if (code[x] == ':') { // If the character is a pipe
        x=x+1; // Go to next variable
        goto xpr;
    } else {
        sskill = sskill + code[x]; // If not add the variables
        x=x+1; // Go to next charcter
        goto skillr;
    }
    xpr:
    if (code[x] == ':') { // If the character is a pipe
        x=x+1; // Go to next variable
        goto xplr;
    } else {
        sxp += code[x]; // If not add the variables
        x=x+1; // Go to next charcter
        goto xpr;
    }
    xplr:
    if (code[x] == ':') { // If the character is a pipe
        x=x+1; // Go to next variable
        goto xpbr;
    } else {
        sxpl = sxpl + code[x]; // If not add the variables
        x=x+1; // Go to next charcter
        goto xplr;
    }
    xpbr:
    if (code[x] == ':') { // If the character is a pipe
        x=x+1; // Go to next variable
        goto levelr;
    } else {
        sxpb = sxpb + code[x]; // If not add the variables
        x=x+1; // Go to next charcter
        goto xpbr;
    }
    levelr:
    if (code[x] == ':') { // If the character is a pipe
        x=x+1; // Go to next variable
        goto hpotionr;
    } else {
        slevel = slevel + code[x]; // If not add the variables
        x=x+1; // Go to next charcter
        goto levelr;
    }
    hpotionr:
    if (code[x] == ':') { // If the character is a pipe
        x=x+1; // Go to next variable
        goto items;
    } else {
        shpotion = shpotion + code[x]; // If not add the variables
        x=x+1; // Go to next charcter
        goto hpotionr;
    }
    items:
    spiclass += code[x];
    x=x+1;
    sslimyhelmet += code[x];
    x=x+1;
    sslimychestplate += code[x];
    x=x+1;
    soozinglegplates += code[x];
    x=x+1;
    soozingboots += code[x];
    goto settingvaribles;

    settingvaribles:

    gold = atoi(sgold.c_str()); // Gold
    stre = atoi(sstre.c_str()); // Strength
    inte = atoi(sinte.c_str()); // Intelligence
    dext = atoi(sdext.c_str()); // Dexterity
    skill = atoi(sskill.c_str()); // Skillpoints
    xp = atoi(sxp.c_str()); // Xp
    xpl = atoi(sxpl.c_str()); // Xp till level
    xpb = atoi(sxpb.c_str()); // Increases xpl
    level = atoi(slevel.c_str()); // Level
    hpotion = atoi(shpotion.c_str()); // HP potions
    piclass = atoi(spiclass.c_str()); // Class
    slimyhelmet = atoi(sslimyhelmet.c_str()); // Slimy Helmet
    slimychestplate = atoi(sslimychestplate.c_str()); // Slimy Chestplate
    oozinglegplates = atoi(soozinglegplates.c_str()); // Oozing Legplates
    oozingboots = atoi(soozingboots.c_str()); // Oozing Boots

    if (piclass == 1) {
        pclass = "Champion";
    } else if (piclass == 2) {
        pclass = "Necromancer";
    } else if (piclass == 3) {
        pclass = "Assassin";
    } else if (piclass == 4) {
        pclass = "Cleric";
    }



    goto compilend;

    compilend:
    clear();

    loadingload:
    y = 0;

    loadingload2:
    if (y < 101) {
        y = y + 1;
        goto loadingload2;
    }

    clear();
    cout << "-------~ Process Complete ~-------" << endl;
    cout << "Please re-input your name" << endl;
    cin >> input;
    name = input;
    goto menue;

    leave:
    clear();
    cout << "See you later!" << endl;

    return 0;
}
