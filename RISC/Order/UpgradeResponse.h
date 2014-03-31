#pragma once
#include "../GameState/GameState.h"
#include "Response.h"
#include "../GameState/Managers/TechnologyManager.h"

using namespace std;

class UpgradeResponse : public Response {
public:
	//response construct for upgrading units
	UpgradeResponse(vector<Unit*>, int);
	//response construct for unlocking units
	UpgradeResponse(vector<UnitType*>, int);
	//resposne construct for making/unmaking spies;
	UpgradeResponse(Unit*,int);
	vector<Unit*> getListOfUpdatedUnits();
	vector<UnitType*> getUpdatedPossUps();
	void setListOfUpdatedUnits(vector<Unit*>);
	void setUpdatedPossUps(vector<UnitType*>);
	void executeResponse(GameState*);
	virtual ~UpgradeResponse();

private:
	bool unlockUp;
	bool upgradUnit;
	bool covertingUnit;

	vector<Unit*> listOfUpdatedUnits;
	Unit* unit;
	vector<UnitType*> updatedPossUps;
	int updatedTechPtAmt;

	


};