# Arduino-Button

## Usage

- `Button` - Base class
- `ActionButton` - Generic Button to track button state and get released / pressed events

- `PinButton` - Simple Button using a digital pin as input
    - `isPressed`
    - `isReleased`

- `PinActionButton` - An ActionButton using a digital input
    - `isPressed`
    - `isReleased`
    - `justPressed`
    - `justReleased`
