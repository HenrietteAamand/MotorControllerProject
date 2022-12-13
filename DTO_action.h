#pragma once
enum ActionEnum
{
	open, close, stop, na 
};

struct DTO_Action {
	ActionEnum actions[5] = {stop, stop, stop, stop, stop}; 
};
