#pragma once

#include "display/lcd_display.h"
#include <string>

/**
 * @brief Otto机器人GIF表情显示类
 * 继承SpiLcdDisplay，通过EmojiCollection添加GIF表情支持
 */
class OttoEmojiDisplay : public SpiLcdDisplay {
   public:
    /**
     * @brief 构造函数，参数与SpiLcdDisplay相同
     */
    OttoEmojiDisplay(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_handle_t panel, int width, int height, int offset_x, int offset_y, bool mirror_x, bool mirror_y, bool swap_xy);

    virtual ~OttoEmojiDisplay() = default;
    virtual void SetStatus(const char* status) override;
    virtual void SetPreviewImage(std::unique_ptr<LvglImage> image) override;
    virtual void SetChatMessage(const char* role, const char* content) override;
    virtual void SetEmotion(const char* emotion) override;

   private:
    void InitializeOttoEmojis();
    // Ugo: stato conversazione per espressioni e gesti
    bool ugo_speaking_ = false;
    bool ugo_thinking_ = false;
    std::string ugo_emotion_ = "neutral";
    int ugo_sentences_ = 0;
    void SetupPreviewImage();
};