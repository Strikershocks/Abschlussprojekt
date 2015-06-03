#include "XMLHandler.hpp"


XMLHandler::XMLHandler(void)
{
	parseXMLDoc();
	// Haupt Node ausw�hlen (Hier w�re das Ergebniss <Options>
	pRoot = doc.first_node();
}


XMLHandler::~XMLHandler(void)
{
}

void XMLHandler::parseXMLDoc()
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);
}

void XMLHandler::initNode(std::string ChildNode)
{
	const char * c = ChildNode.c_str();
	pNode = pRoot->first_node(c);
}

void XMLHandler::initAttribut(std::string Attribut)
{
	const char * c = Attribut.c_str();
	pAttr = pNode->first_attribute(c);
}

std::string XMLHandler::loadPlayerName()
{
	// Auswahl des Child Nodes <Player>
	initNode("Player");

	// Von Child Node <Player> das Attribut Name ausw�hlen
	initAttribut("Name");

	// R�ckgabe Spielername
	return pAttr->value();
}


int XMLHandler::loadPlayerSkinIndex()
{
	// Auswahl des Child Nodes <Player>
	initNode("Player");

	// Von Child Node <Player> das Attribut SkinIndex ausw�hlen
	initAttribut("SkinIndex");

	//R�ckgabe von den SkinIndex
	return atoi(pAttr->value());
}

int XMLHandler::loadAliasing()
{
	// Auswahl des Child Nodes <Aliasing>
	initNode("Aliasing");

	// Von Child Node <Stufe> das Attribut SkinIndex ausw�hlen
	initAttribut("Stufe");

	// R�ckgabe Aliasing Stufe
	return atoi(pAttr->value());
}

int XMLHandler::loadWinX()
{
	// Auswahl des Child Nodes <Window>
	initNode("Window");

	// Von Child Node <Window> das Attribut X ausw�hlen
	initAttribut("X");

	// R�ckgabe von WinX
	return atoi(pAttr->value());
}

int XMLHandler::loadWinY()
{
	// Auswahl des Child Nodes <Window>
	initNode("Window");

	// Von Child Node <Window> das Attribut Y ausw�hlen
	initAttribut("Y");

	// R�ckgabe von WinY
	return atoi(pAttr->value());
}

std::string XMLHandler::loadRanking(int index)
{
	std::string Name, Time, Platz, Returntext;
	// Auswahl des Child Nodes <RankingPlace>
	initNode("RankingPlace");

	// Von Child Node <RankingPlace> das Attribut Place + index ausw�hlen
	initAttribut("Place" + index);

	// Name wird gespeichert
	Name = pAttr->value();

	// Auswahl des Child Nodes <RankingTime>
	initNode("RankingTime");

	// Von Child Node <RankingTime> das Attribut Time + index ausw�hlen
	initAttribut("Time" + index);
	
	// Zeit wird gespeichert
	Time = pAttr->value();

	// Zusammenstellung des Platz Textes 
	Platz = "Platz: " + index;
	Name = " Spieler: " + Name;
	Time = " Zeit: " + Time;
	Returntext = Platz + Name + Time; 

	return Returntext;
}

void XMLHandler::savePlayerName(std::string player)
{
	const char * c = player.c_str();
	// Auswahl des Child Nodes <Player>
	initNode("Player");

	// Von Child Node <Player> das Attribut Name ausw�hlen
	initAttribut("Name");
	
	
	// �ndern des Attributs.
	pAttr->value(doc.allocate_string(c));
}

void XMLHandler::XMLSave()
{
	std::ofstream file_stored("settings.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
	file_stored << doc;
	file_stored.close();
	doc.clear();
}

void XMLHandler::savePlayerSkinIndex(int index)
{
	char pbuff[32];
	itoa(index, pbuff, 10);

	// Auswahl des Child Nodes <Player>
	initNode("Player");

	// Von Child Node <Player> das Attribut SkinIndex ausw�hlen
	initAttribut("SkinIndex");
	
	// �ndern des Attributs.
	pAttr->value(doc.allocate_string(pbuff));
}

void XMLHandler::saveAliasing(int Aliasing)
{
	char pbuff[32];
	itoa(Aliasing, pbuff, 10);

	// Auswahl des Child Nodes <Aliasing>
	initNode("Aliasing");

	// Von Child Node <Aliasing> das Attribut Stufe ausw�hlen
	initAttribut("Stufe");
	
	// �ndern des Attributs.
	pAttr->value(doc.allocate_string(pbuff));
}

void XMLHandler::saveWinXY(int x, int y)
{
	char pbuffX[32];
	itoa(x, pbuffX, 10);

	char pbuffY[32];
	itoa(y, pbuffY, 10);

	// Auswahl des Child Nodes <Window>
	initNode("Window");

	// Von Child Node <Window> das Attribut X ausw�hlen
	initAttribut("X");
	
	// �ndern des Attributs.
	pAttr->value(doc.allocate_string(pbuffX));

	// Von Child Node <Window> das Attribut Y ausw�hlen
	initAttribut("Y");

	// �ndern des Attributs.
	pAttr->value(doc.allocate_string(pbuffY));
}