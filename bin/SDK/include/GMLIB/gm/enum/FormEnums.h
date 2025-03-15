#pragma once
namespace gmlib::form {

// NPC Dialogue Form
enum class NpcDialogueFormAction : int {
    Button = 0, // Button Mode
    Close  = 1, // Open Command
    Open   = 2  // Close Command
};

// Server Setting Form
enum class IconType : unsigned char { Texture = 0, Url = 1 };

} // namespace gmlib::form
