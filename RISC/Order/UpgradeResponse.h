#pragma once
#include "../GameState/GameState.h"
#include "Response.h"
#include "../GameState/Managers/TechnologyManager.h"

using namespace std;

class UpgradeResponse : public Response {
public:
	UpgradeResponse(vector<Unit*>, int);
	UpgradeResponse(vector<UnitType*>, int);
	vector<Unit*> getListOfUpdatedUnits();
	vector<UnitType*> getUpdatedPossUps();
	void setListOfUpdatedUnits(vector<Unit*>);
	void setUpdatedPossUps(vector<UnitType*>);
	void executeResponse(GameState*);
	virtual ~UpgradeResponse();

private:
	vector<Unit*> listOfUpdatedUnits;
	vector<UnitType*> updatedPossUps;
	int updatedTechPtAmt;

	


};