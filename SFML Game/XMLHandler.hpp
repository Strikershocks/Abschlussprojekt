#pragma once
#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"
#include <sstream>

using namespace rapidxml;

class XMLHandler
{
public:
	XMLHandler(void);
	~XMLHandler(void);

	// Reinladen des XMLDocs
	void parseXMLDoc();

	// XML Getter
	std::string loadPlayerName();
	int loadPlayerSkinIndex();
	int loadWinX();
	int loadWinY();
	int loadAliasing();
	std::string loadRanking(int index);

	// XML Setter
	void savePlayerName(std::string Name);
	void savePlayerSkinIndex(int index);
	void saveWinXY(int x, int y);
	void saveAliasing(int Stufe);
	void initNode(std::string ChildNode);
	void initAttribut(std::string Attribut);

	// Speichern des Dokuments
	void XMLSave();

private:
	xml_document<> doc;
	xml_node<> *pRoot ;
	xml_node<> *pNode;
	xml_attribute<> *pAttr;
};

