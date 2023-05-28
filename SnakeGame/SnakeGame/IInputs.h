#pragma once

/// <summary>
/// Abstracts user inputs. Specifies which inputs the user has made since the last frame was processed.
/// </summary>
class IInputs
{
public:
	/// <summary>
	/// Gets a value indicating whether the "up" input has been given.
	/// </summary>
	virtual bool IsUp() const = 0;

	/// <summary>
	/// Gets a value indicating whether the "down" input has been given.
	/// </summary>
	virtual bool IsDown() const = 0;

	/// <summary>
	/// Gets a value indicating whether the "left" input has been given.
	/// </summary>
	virtual bool IsLeft() const = 0;

	/// <summary>
	/// Gets a value indicating whether the "right" input has been given.
	/// </summary>
	virtual bool IsRight() const = 0;
};