#include <cstdint>
#include <iostream>

void run_manipulation_and_masks()
{
    [[maybe_unused]] constexpr std::uint8_t mask1{
        0b0000'0001};  // represents bit 0
    [[maybe_unused]] constexpr std::uint8_t mask2{
        0b0000'0010};  // represents bit 1
    [[maybe_unused]] constexpr std::uint8_t mask3{
        0b0000'0100};  // represents bit 2
    [[maybe_unused]] constexpr std::uint8_t mask4{
        0b0000'1000};  // represents bit 3
    [[maybe_unused]] constexpr std::uint8_t mask5{
        0b0001'0000};  // represents bit 4
    [[maybe_unused]] constexpr std::uint8_t mask6{
        0b0010'0000};  // represents bit 5
    [[maybe_unused]] constexpr std::uint8_t mask7{
        0b0100'0000};  // represents bit 6
    [[maybe_unused]] constexpr std::uint8_t mask8{
        0b1000'0000};  // represents bit 7

    // We can also use hex or bit shifting
    // constexpr std::uint8_t mask1{ 0x01 }; // represents bit 0
    // constexpr std::uint8_t mask2{ 0x02 }; // represents bit 1
    // constexpr std::uint8_t mask3{ 0x04 }; // represents bit 2
    // constexpr std::uint8_t mask4{ 0x08 }; // represents bit 3
    // constexpr std::uint8_t mask5{ 0x10 }; // represents bit 4
    // constexpr std::uint8_t mask6{ 0x20 }; // represents bit 5
    // constexpr std::uint8_t mask7{ 0x40 }; // represents bit 6
    // constexpr std::uint8_t mask8{ 0x80 }; // represents bit 7

    // constexpr std::uint8_t mask1{ 1 << 0 }; // represents bit 0
    // constexpr std::uint8_t mask2{ 1 << 1 }; // represents bit 1
    // constexpr std::uint8_t mask3{ 1 << 2 }; // represents bit 2
    // constexpr std::uint8_t mask4{ 1 << 3 }; // represents bit 3
    // constexpr std::uint8_t mask5{ 1 << 4 }; // represents bit 4
    // constexpr std::uint8_t mask6{ 1 << 5 }; // represents bit 5
    // constexpr std::uint8_t mask7{ 1 << 6 }; // represents bit 6
    // constexpr std::uint8_t mask8{ 1 << 7 }; // represents bit 7

    std::uint8_t flags{0b0000'0101};
    // Use bitwise AND to determine if a particular bit is set
    std::cout << "Bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
    std::cout << "Bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    // ...

    // Use bitwise OR to set a particular bit
    flags |= mask1;  // turn on bit 1
    std::cout << "Bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    // We can turn on multiple bits at once
    flags |= (mask1 | mask2);  // turn on bits 1 and 2
    std::cout << "Bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    // To turn off a bit, we use bitwise AND with the complement of the mask
    flags &= ~mask1;  // turn off bit 1
    std::cout << "Bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    // We can turn off multiple bits at once
    flags &= ~(mask1 | mask2);  // turn off bits 1 and 2
    std::cout << "Bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    // To toggle a bit, we use bitwise XOR
    flags ^= mask1;  // toggle bit 1
    std::cout << "Bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    // We can flip multiple bits at once
    flags ^= (mask1 | mask2);  // toggle bits 1 and 2
    std::cout << "Bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    // We can use bitmasks with multiple bits
    // Let's use this example with RGBA colors
    constexpr std::uint32_t red_mask{0xFF000000};
    constexpr std::uint32_t green_mask{0x00FF0000};
    constexpr std::uint32_t blue_mask{0x0000FF00};
    constexpr std::uint32_t alpha_mask{0x000000FF};

    std::uint32_t pixel_color{0xDAA520FF};  // 0xDAA520FF is a golden color

    // Combine bitwise AND with a shift to extract individual color components
    std::uint8_t red{static_cast<std::uint8_t>((pixel_color & red_mask) >> 24)};
    std::uint8_t green{
        static_cast<std::uint8_t>((pixel_color & green_mask) >> 16)};
    std::uint8_t blue{
        static_cast<std::uint8_t>((pixel_color & blue_mask) >> 8)};
    std::uint8_t alpha{static_cast<std::uint8_t>(pixel_color & alpha_mask)};

    // Let's print in hex
    std::cout << std::hex;
    std::cout << "Red: " << static_cast<int>(red) << '\n';
    std::cout << "Green: " << static_cast<int>(green) << '\n';
    std::cout << "Blue: " << static_cast<int>(blue) << '\n';
    std::cout << "Alpha: " << static_cast<int>(alpha) << '\n';
}