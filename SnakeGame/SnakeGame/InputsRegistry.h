#include "IInputs.h"

/// <summary>
/// Specifies and registers which inputs the user has made since the last frame was processed.
/// </summary>
class InputsRegistry : public IInputs
{
public:
	InputsRegistry() = default;
	~InputsRegistry() = default;

	bool IsUp() const;
	bool IsDown() const;
	bool IsLeft() const;
	bool IsRight() const;

	void RegisterUp();
	void RegisterDown();
	void RegisterLeft();
	void RegisterRight();

	void Reset();

private:
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = true;
};