#pragma once
enum ActionEnum
{
	open, close, stop, na 
};

struct DTO_Action {
	ActionEnum actions[5] = {open, open, open, open, open}; 
};
