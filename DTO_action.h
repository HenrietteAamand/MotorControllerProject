#pragma once
enum ActionEnum
{
	open, close, stop, na // OBS! skal kommunikeres til Sabrina
};

struct DTO_Action {
	ActionEnum actions[5] = {open, open, open, open, open}; // OBS! skal fyldes opn�r jeg modtager DTO Action
};
