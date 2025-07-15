# Placeholder 文档

## 教程

### 基础语法结构

PAPI 支持两种占位符格式：

#### 1. 简单变量格式

```papi
%变量名%
```

- 直接调用内置变量
- 示例：`%player_realname%`, `%server_tps%`

#### 2. 带参数表达式格式

```papi
${papi:变量名:参数}
```

- 支持复杂的表达式，扩展一些复杂操作
- 基本结构：`${papi:变量名, 参数1, 参数2, ...}`

---

### 函数表达式详解

#### 函数调用层级结构

```papi
${papi:函数名, 参数}
   ├─ 函数名 (必填)
   └─ 参数列表 (可选)
```

#### 参数分隔符规则

| 位置             | 允许的分隔符        | 示例                          |
| ---------------- | ------------------- | ----------------------------- |
| 变量名与参数之间 | `:`, `,`, `;`, `\|` | `${papi:变量名\|参数}`        |
| 参数与参数之间   | `,` (仅逗号)        | `${papi:变量名;参数1, 参数2}` |

---

### 嵌套表达式格式

#### 基础嵌套结构

```
${papi:外层变量名, 参数=${papi:内层变量名,参数}}
```

#### 多级嵌套示例

```papi
${
    papi:dict,
    input=${
        papi:compare,
        compare=>, // 实际的比较符号为“>”，这里的“=”是参数键值分隔符
        left=${
            papi:entity_health
        },
        right=10
    },
    true=健康,
    false=虚弱
}
```

- `${papi:entity_health}` -> `20`
- `${papi:compare, compare=>, left=20, right=10}` -> `true`
- `${papi:dict, input=true, true=健康, false=虚弱}` -> `健康`

---

### 特殊字符转义规则

在参数值中使用 `\` 转义特殊字符：

```papi
${papi:format: format={0} \, {1}, 0=X, 1=Y}
```

---

## 默认变量

### 玩家变量

#### player_name (玩家名)

- 示例返回值: `zimuya4153`

#### player_uuid (玩家的 uuid)

- 示例返回值: `61708b79-cdc0-3cbf-8491-49b2b14fd7e3`

#### player_ping (玩家的延迟)

- 示例返回值: `35`

#### player_gamemode (玩家的游戏模式)

- 示例返回值: `Survival`, `Creative`, `Adventure`, `Default`, `Spectator`

#### player_flying (玩家是否在飞行)

- 示例返回值: `true`, `false`

#### player_can_fly (玩家是否可以飞行)

- 示例返回值: `true`, `false`

#### player_is_op (玩家是否是 OP)

- 示例返回值: `true`, `false`

#### player_permlevel (玩家的权限等级)

- 示例返回值: `Any`, `GameDirectors`, `Admin`, `Host`, `Owner`, `Internal`

#### player_ip (玩家的 IP 地址)

- 示例返回值: `192.168.1.1:55536`

#### player_device (玩家的设备类型)

- 示例返回值: `Google`, `IOS`, `Osx`, `Amazon`, `GearVRDeprecated`, `Uwp`, `Win32`, `Dedicated`, `TvOSDeprecated`, `Sony`, `Nx`, `Xbox`, `WindowsPhoneDeprecated`, `Linux`, `Unknown`

#### player_language (玩家的语言)

- 示例返回值: `en_US`, `en_GB`, `de_DE`, `es_ES`, `es_MX`, `fr_FR`, `fr_CA`, `it_IT`, `ja_JP`, `ko_KR`, `pt_BR`, `pt_PT`, `ru_RU`, `zh_CN`, `zh_TW`, `nl_NL`, `bg_BG`, `cs_CZ`, `da_DK`, `el_GR`, `fi_FI`, `hu_HU`, `id_ID`, `nb_NO`, `pl_PL`, `sk_SK`, `sv_SE`, `tr_TR`, `uk_UA`

#### player_xuid (玩家的 XUID)

- 示例返回值: `2535418305845290`

#### player_bed_pos (玩家的重生位置)

- 参数:
  - `format`: 返回格式(可选)
    - 默认: `({0}, {1}, {2})`

#### player_hunger (玩家的饥饿度)

- 示例返回值: `20`

#### player_max_hunger (玩家的最大饥饿度)

- 示例返回值: `20`

#### player_saturation (玩家的饱和度)

- 示例返回值: `20`

#### player_max_saturation (玩家的最大饱和度)

- 示例返回值: `20`

#### player_protocol_version (玩家的协议版本)

- 示例返回值: `776`

#### player_llmoney (玩家的在 llmoney 中的经济)

- 示例返回值: `1000`

#### player_exp_level (玩家的经验等级)

- 示例返回值: `10`

### 实体变量

#### entity_name (实体的命名)

- 示例返回值: `子沐的小宠物`

#### entity_type_name (实体的类型)

- 示例返回值: `minecraft:wolf`

#### entity_health (实体的生命值)

- 示例返回值: `20`

#### entity_max_health (实体的最大生命值)

- 示例返回值: `20`

#### entity_pos (实体的坐标)

- 参数:
  - `format`: 返回格式(可选)
    - 默认: `({0:.2f}, {1:.2f}, {2:.2f})`
- 示例返回值: `(-0.00, 64.00, 0.00)`

#### entity_rotation (实体的朝向)

- 参数:
  - `format`: 返回格式(可选)
    - 默认: `({0:.2f}, {1:.2f})`
- 示例返回值: `(0.00, 0.00)`

#### entity_score (实体的计分板值)

- 参数:
  - `objective`: 计分板名称
- 示例返回值: `100`

#### entity_biome (实体所在群系)

- 示例返回值: <details>`ocean`, `plains`, `desert`, `extreme_hills`, `forest`, `taiga`, `swampland`, `river`, `hell`, `the_end`, `legacy_frozen_ocean`, `frozen_river`, `ice_plains`, `ice_mountains`, `mushroom_island`, `mushroom_island_shore`, `beach`, `desert_hills`, `forest_hills`, `taiga_hills`, `extreme_hills_edge`, `jungle`, `jungle_hills`, `jungle_edge`, `deep_ocean`, `stone_beach`, `cold_beach`, `birch_forest`, `birch_forest_hills`, `roofed_forest`, `cold_taiga`, `cold_taiga_hills`, `mega_taiga`, `mega_taiga_hills`, `extreme_hills_plus_trees`, `savanna`, `savanna_plateau`, `mesa`, `mesa_plateau_stone`, `mesa_plateau`, `warm_ocean`, `deep_warm_ocean`, `lukewarm_ocean`, `deep_lukewarm_ocean`, `cold_ocean`, `deep_cold_ocean`, `frozen_ocean`, `deep_frozen_ocean`, `bamboo_jungle`, `bamboo_jungle_hills`, `sunflower_plains`, `desert_mutated`, `extreme_hills_mutated`, `flower_forest`, `taiga_mutated`, `swampland_mutated`, `ice_plains_spikes`, `jungle_mutated`, `jungle_edge_mutated`, `birch_forest_mutated`, `birch_forest_hills_mutated`, `roofed_forest_mutated`, `cold_taiga_mutated`, `redwood_taiga_mutated`, `redwood_taiga_hills_mutated`, `extreme_hills_plus_trees_mutated`, `savanna_mutated`, `savanna_plateau_mutated`, `mesa_bryce`, `mesa_plateau_stone_mutated`, `mesa_plateau_mutated`, `soulsand_valley`, `crimson_forest`, `warped_forest`, `basalt_deltas`, `jagged_peaks`, `frozen_peaks`, `snowy_slopes`, `grove`, `meadow`, `lush_caves`, `dripstone_caves`, `stony_peaks`, `deep_dark`, `mangrove_swamp`, `cherry_grove`, `pale_garden`, `ocean`, `plains`, `desert`, `extreme_hills`, `forest`, `taiga`, `swampland`, `river`, `hell`, `the_end`, `legacy_frozen_ocean`, `frozen_river`, `ice_plains`, `ice_mountains`, `mushroom_island`, `mushroom_island_shore`, `beach`, `desert_hills`, `forest_hills`, `taiga_hills`, `extreme_hills_edge`, `jungle`, `jungle_hills`, `jungle_edge`, `deep_ocean`, `stone_beach`, `cold_beach`, `birch_forest`, `birch_forest_hills`, `roofed_forest`, `cold_taiga`, `cold_taiga_hills`, `mega_taiga`, `mega_taiga_hills`, `extreme_hills_plus_trees`, `savanna`, `savanna_plateau`, `mesa`, `mesa_plateau_stone`, `mesa_plateau`, `warm_ocean`, `deep_warm_ocean`, `lukewarm_ocean`, `deep_lukewarm_ocean`, `cold_ocean`, `deep_cold_ocean`, `frozen_ocean`, `deep_frozen_ocean`, `bamboo_jungle`, `bamboo_jungle_hills`, `sunflower_plains`, `desert_mutated`, `extreme_hills_mutated`, `flower_forest`, `taiga_mutated`, `swampland_mutated`, `ice_plains_spikes`, `jungle_mutated`, `jungle_edge_mutated`, `birch_forest_mutated`, `birch_forest_hills_mutated`, `roofed_forest_mutated`, `cold_taiga_mutated`, `redwood_taiga_mutated`, `redwood_taiga_hills_mutated`, `extreme_hills_plus_trees_mutated`, `savanna_mutated`, `savanna_plateau_mutated`, `mesa_bryce`, `mesa_plateau_stone_mutated`, `mesa_plateau_mutated`, `soulsand_valley`, `crimson_forest`, `warped_forest`, `basalt_deltas`, `jagged_peaks`, `frozen_peaks`, `snowy_slopes`, `grove`, `meadow`, `lush_caves`, `dripstone_caves`, `stony_peaks`, `deep_dark`, `mangrove_swamp`, `cherry_grove`, `pale_garden`, `ocean`, `plains`, `desert`, `extreme_hills`, `forest`, `taiga`, `swampland`, `river`, `hell`, `the_end`, `legacy_frozen_ocean`, `frozen_river`, `ice_plains`, `ice_mountains`, `mushroom_island`, `mushroom_island_shore`, `beach`, `desert_hills`, `forest_hills`, `taiga_hills`, `extreme_hills_edge`, `jungle`, `jungle_hills`, `jungle_edge`, `deep_ocean`, `stone_beach`, `cold_beach`, `birch_forest`, `birch_forest_hills`, `roofed_forest`, `cold_taiga`, `cold_taiga_hills`, `mega_taiga`, `mega_taiga_hills`, `extreme_hills_plus_trees`, `savanna`, `savanna_plateau`, `mesa`, `mesa_plateau_stone`, `mesa_plateau`, `warm_ocean`, `deep_warm_ocean`, `lukewarm_ocean`, `deep_lukewarm_ocean`, `cold_ocean`, `deep_cold_ocean`, `frozen_ocean`, `deep_frozen_ocean`, `bamboo_jungle`, `bamboo_jungle_hills`, `sunflower_plains`, `desert_mutated`, `extreme_hills_mutated`, `flower_forest`, `taiga_mutated`, `swampland_mutated`, `ice_plains_spikes`, `jungle_mutated`, `jungle_edge_mutated`, `birch_forest_mutated`, `birch_forest_hills_mutated`, `roofed_forest_mutated`, `cold_taiga_mutated`, `redwood_taiga_mutated`, `redwood_taiga_hills_mutated`, `extreme_hills_plus_trees_mutated`, `savanna_mutated`, `savanna_plateau_mutated`, `mesa_bryce`, `mesa_plateau_stone_mutated`, `mesa_plateau_mutated`, `soulsand_valley`, `crimson_forest`, `warped_forest`, `basalt_deltas`, `jagged_peaks`, `frozen_peaks`, `snowy_slopes`, `grove`, `meadow`, `lush_caves`, `dripstone_caves`, `stony_peaks`, `deep_dark`, `mangrove_swamp`, `cherry_grove`, `pale_garden`
</details>

### 服务端变量

#### server_time (服务器时间)

- 参数:
  - `format`: 时间格式 (默认为 `%H:%M:%S`)
  - `timezone`: 时区 (默认以服务端时区为准)
- 返回值示例: `12:34:56`

> **注意**: 如果传入了`timezone`参数优先以`timezone`为准, 如果`timezone`参数为空则使用传入的玩家时区，如果玩家时区为空最后才使用服务端时区

#### server_online (在线玩家数)

- 返回值示例: `1`

#### server_max_players (服务器最大玩家数)

- 返回值示例: `20`

#### server_version (服务器版本)

- 参数:
  - `preRelease`: 是否包含预发布版本 (默认为 `false`)
  - `build`: 是否包含构建号 (默认为 `false`)
- 返回值示例: `1.21.80.04`

#### levilamina_version (加载器版本)

- 参数:
  - `preRelease`: 是否包含预发布版本 (默认为 `false`)
  - `build`: 是否包含构建号 (默认为 `false`)
- 返回值示例: `1.3.0`

#### server_protocol_version (服务端协议版本)

- 返回值示例: `760`

#### server_total_entities (服务端实体总数)

- 参数:
  - `type`: 实体类型筛选 (可选)
- 返回值示例: `100`

#### server_world_name (存档名)

- 返回值示例: `Bedrock level`

#### server_difficulty (服务端难度)

- 返回值示例: `Peaceful`, `Easy`, `Normal`, `Hard`

#### server_on_allowlist (是否开启白名单)

- 返回值示例: `true`, `false`

#### server_port (服务器 IPv4 端口)

- 返回值示例: `19132`

#### server_port_v6 (服务器 IPv6 端口)

- 返回值示例: `19133`

#### server_uptime (服务器运行时间)

- 返回值示例: `124` (单位为秒)

#### server_start_time (服务器启动时间)

- 参数:
  - `format`: 时间格式 (默认为 `{:%H:%M:%S}`)
- 返回值示例: `12:34:56`

#### server_name (服务器名称)

- 返回值示例: `Dedicated Server`

#### server_has_whitelist (是否开启白名单)

- 返回值示例: `true`, `false`

#### server_ram_bds_used (服务端内存使用量)

- 返回值示例: `457`

#### server_ram_free (服务器未使用内存)

- 返回值示例: `1001`

#### server_ram_used (服务器已使用内存)

- 返回值示例: `14261`

#### server_ram_max (服务器最大内存)

- 返回值示例: `16131`

#### server_tps (服务器 TPS)

- 参数:
  - `decimals`: 小数位数 (默认为 `2`)
- 返回值示例: `20.00`

#### server_tps_colored (带颜色的服务器 TPS)

- 返回值示例: `§a20.00`

> **注意**: 大于等于 20 为§a, 15-19 为§6, 小于 15 为§c

#### server_mspt (服务器 MSPT)

- 参数:
  - `decimals`: 小数位数 (默认为 `2`)
- 返回值示例: `50.00`

#### server_mspt_colored (带颜色的服务器 MSPT)

- 返回值示例: `§a50.00`

> **注意**: 小于等于 50 为§a, 100-50 为§6, 大于 100 为§c

#### i18n_translate (I18n 翻译)

- 参数:
  - `key`: 翻译键
  - `0..n`: 翻译参数
  - `language`: 语言 (默认已服务端为准)
- 输入示例: `${papi:i18n_translate,key=multiplayer.player.joined,language=zh_CN,0=玩家名}`
- 返回值示例: `玩家名 加入了游戏`

#### system_locale_code (系统语言代码)

- 返回值示例: `zh-CN`

#### system_name (系统名称)

- 返回值示例: `Windows 10 专业版`

#### system_version (系统版本)

- 返回值示例: `10.0.19045`

#### environment_variable (环境变量)

- 参数:
  - `name`: 环境变量名
- 输入示例: `${papi:environment_variable,name=appdata}`
- 返回值示例: `C:\Users\Administrator\AppData\Roaming`

### Emoji

| Emoji 名                                | Unicode  | 图片                                                                                                |
| --------------------------------------- | -------- | --------------------------------------------------------------------------------------------------- |
| emoji_food                              | `U+E100` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/hud/food.png)                            |
| emoji_armor                             | `U+E101` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/hud/armor.png)                           |
| emoji_heart                             | `U+E10C` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/hud/heart.png)                           |
| emoji_wooden_pickaxe                    | `U+E108` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/items/wooden_pickaxe.png)                |
| emoji_wooden_sword                      | `U+E109` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/items/wooden_sword.png)                  |
| emoji_crafting_table                    | `U+E10A` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/items/crafting_table.png)                |
| emoji_furnace                           | `U+E10B` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/items/furnace.png)                       |
| emoji_minecoin                          | `U+E102` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/marketplace/minecoin.png)                |
| emoji_token                             | `U+E105` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/marketplace/token.png)                   |
| emoji_craft_toggle_on                   | `U+E0A0` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/inventory/craft_toggle_on.png)           |
| emoji_craft_toggle_off                  | `U+E0A1` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/inventory/craft_toggle_off.png)          |
| emoji_jump_touch                        | `U+E014` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/new_touch/jump.png)                      |
| emoji_attack_touch                      | `U+E015` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/new_touch/attack.png)                    |
| emoji_joy_stick_touch                   | `U+E016` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/new_touch/joystick.png)                  |
| emoji_place_touch                       | `U+E018` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/new_touch/place.png)                     |
| emoji_sneak_touch                       | `U+E019` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/new_touch/sneak.png)                     |
| emoji_sprint_touch                      | `U+E01A` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/new_touch/sprint.png)                    |
| emoji_fly_up_touch                      | `U+E01B` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/new_touch/fly_up.png)                    |
| emoji_fly_down_touch                    | `U+E01C` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/new_touch/fly_down.png)                  |
| emoji_dismount_touch                    | `U+E01D` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/new_touch/dismount.png)                  |
| emoji_jump_small_touch                  | `U+E084` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/touch/jump.png)                          |
| emoji_crouch_small_touch                | `U+E085` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/touch/crouch.png)                        |
| emoji_fly_up_small_touch                | `U+E086` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/touch/fly_up.png)                        |
| emoji_fly_down_small_touch              | `U+E087` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/touch/fly_down.png)                      |
| emoji_stop_flying_small_touch           | `U+E088` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/touch/stop_flying.png)                   |
| emoji_left_arrow_small_touch            | `U+E081` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/touch/left_arrow.png)                    |
| emoji_right_arrow_small_touch           | `U+E083` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/touch/right_arrow.png)                   |
| emoji_up_arrow_small_touch              | `U+E080` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/touch/up_arrow.png)                      |
| emoji_down_arrow_small_touch            | `U+E082` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/touch/down_arrow.png)                    |
| emoji_left_click                        | `U+E060` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/keyboard/left_click.png)                 |
| emoji_right_click                       | `U+E061` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/keyboard/right_click.png)                |
| emoji_middle_click                      | `U+E062` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/keyboard/middle_click.png)               |
| emoji_small_left_click                  | `U+E070` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/keyboard/small_left_click.png)           |
| emoji_small_right_click                 | `U+E071` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/keyboard/small_right_click.png)          |
| emoji_small_middle_click                | `U+E072` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/keyboard/small_middle_click.png)         |
| emoji_small_mouse                       | `U+E073` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/keyboard/small_mouse.png)                |
| emoji_xbox_y                            | `U+E003` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/y_button.png)                       |
| emoji_xbox_b                            | `U+E001` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/b_button.png)                       |
| emoji_xbox_a                            | `U+E000` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/a_button.png)                       |
| emoji_xbox_x                            | `U+E002` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/x_button.png)                       |
| emoji_xbox_back                         | `U+E008` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/back.png)                           |
| emoji_xbox_start                        | `U+E009` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/start.png)                          |
| emoji_xbox_lb                           | `U+E004` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/left_bumper.png)                    |
| emoji_xbox_rb                           | `U+E005` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/right_bumper.png)                   |
| emoji_xbox_lt                           | `U+E006` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/left_trigger.png)                   |
| emoji_xbox_rt                           | `U+E007` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/right_trigger.png)                  |
| emoji_xbox_ls                           | `U+E00A` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/left_stick.png)                     |
| emoji_xbox_rs                           | `U+E00B` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/right_stick.png)                    |
| emoji_xbox_d_pad_up                     | `U+E00C` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/dpad_up.png)                        |
| emoji_xbox_d_pad_right                  | `U+E00F` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/dpad_right.png)                     |
| emoji_xbox_d_pad_down                   | `U+E00E` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/dpad_down.png)                      |
| emoji_xbox_d_pad_left                   | `U+E00D` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/xbox/dpad_left.png)                      |
| emoji_switch_x                          | `U+E042` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/x_button.png)                     |
| emoji_switch_a                          | `U+E040` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/a_button.png)                     |
| emoji_switch_b                          | `U+E041` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/b_button.png)                     |
| emoji_switch_y                          | `U+E043` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/y_button.png)                     |
| emoji_switch_plus                       | `U+E049` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/plus.png)                         |
| emoji_switch_minus                      | `U+E048` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/minus.png)                        |
| emoji_switch_l                          | `U+E044` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/left_bumper.png)                  |
| emoji_switch_r                          | `U+E045` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/right_bumper.png)                 |
| emoji_switch_zl                         | `U+E046` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/left_trigger.png)                 |
| emoji_switch_rl                         | `U+E047` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/right_trigger.png)                |
| emoji_switch_l_stick                    | `U+E04A` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/left_stick.png)                   |
| emoji_switch_r_stick                    | `U+E04B` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/right_stick.png)                  |
| emoji_switch_d_pad_up                   | `U+E04C` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/dpad_up.png)                      |
| emoji_switch_d_pad_right                | `U+E04F` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/dpad_right.png)                   |
| emoji_switch_d_pad_down                 | `U+E04E` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/dpad_down.png)                    |
| emoji_switch_d_pad_left                 | `U+E04D` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/switch/dpad_left.png)                    |
| emoji_ps_triangle                       | `U+E023` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/triangle.png)                |
| emoji_ps_circle                         | `U+E021` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/circle.png)                  |
| emoji_ps_cross                          | `U+E020` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/cross.png)                   |
| emoji_ps_square                         | `U+E022` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/square.png)                  |
| emoji_ps_options_share                  | `U+E029` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/options_share.png)           |
| emoji_ps_touch_pad                      | `U+E028` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/touch_pad.png)               |
| emoji_ps_l1                             | `U+E024` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/left_bumper.png)             |
| emoji_ps_r1                             | `U+E025` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/right_bumper.png)            |
| emoji_ps_l2                             | `U+E026` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/left_trigger.png)            |
| emoji_ps_r2                             | `U+E027` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/right_trigger.png)           |
| emoji_ps_l3                             | `U+E02A` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/left_stick.png)              |
| emoji_ps_r3                             | `U+E02B` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/right_stick.png)             |
| emoji_ps_d_pad_up                       | `U+E02C` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/dpad_up.png)                 |
| emoji_ps_d_pad_right                    | `U+E02F` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/dpad_right.png)              |
| emoji_ps_d_pad_down                     | `U+E02E` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/dpad_down.png)               |
| emoji_ps_d_pad_left                     | `U+E02D` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/playstation/dpad_left.png)               |
| emoji_oculus_0                          | `U+E0E0` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/oculus/0_button.png)                     |
| emoji_oculus_b                          | `U+E0E2` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/oculus/b_button.png)                     |
| emoji_oculus_a                          | `U+E0E1` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/oculus/a_button.png)                     |
| emoji_oculus_y                          | `U+E0EA` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/oculus/y_button.png)                     |
| emoji_oculus_x                          | `U+E0E9` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/oculus/x_button.png)                     |
| emoji_oculus_lg                         | `U+E0E3` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/oculus/left_grip.png)                    |
| emoji_oculus_rg                         | `U+E0E4` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/oculus/right_grip.png)                   |
| emoji_oculus_lt                         | `U+E0E7` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/oculus/left_trigger.png)                 |
| emoji_oculus_rt                         | `U+E0E8` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/oculus/right_trigger.png)                |
| emoji_oculus_ls                         | `U+E0E5` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/oculus/left_stick.png)                   |
| emoji_oculus_rs                         | `U+E0E6` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/oculus/right_stick.png)                  |
| emoji_windows_menu                      | `U+E0C2` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/windowsMR/menu.png)                      |
| emoji_windows_key                       | `U+E0CD` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/windowsMR/windows.png)                   |
| emoji_windows_left_touchpad             | `U+E0C5` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/windowsMR/left_touchpad.png)             |
| emoji_windows_left_horizontal_touchpad  | `U+E0C6` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/windowsMR/left_touchpad_horizontal.png)  |
| emoji_windows_left_vertical_touchpad    | `U+E0C7` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/windowsMR/left_touchpad_vertical.png)    |
| emoji_windows_right_touchpad            | `U+E0C8` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/windowsMR/right_touchpad.png)            |
| emoji_windows_right_horizontal_touchpad | `U+E0C9` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/windowsMR/right_touchpad_horizontal.png) |
| emoji_windows_right_vertical_touchpad   | `U+E0CA` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/windowsMR/right_touchpad_vertical.png)   |
| emoji_windows_lt                        | `U+E0CB` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/windowsMR/left_trigger.png)              |
| emoji_windows_rt                        | `U+E0CC` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/windowsMR/right_trigger.png)             |
| emoji_windows_lg                        | `U+E0C0` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/windowsMR/left_grab.png)                 |
| emoji_windows_rg                        | `U+E0C1` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/windowsMR/right_grab.png)                |
| emoji_windows_ls                        | `U+E0C3` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/windowsMR/left_stick.png)                |
| emoji_windows_rs                        | `U+E0C4` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/windowsMR/right_stick.png)               |
| emoji_crosshair                         | `U+E017` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/other/crosshair.png)                     |
| emoji_agent                             | `U+E103` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/other/agent.png)                         |
| emoji_immersive_reader                  | `U+E104` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/other/immersive_reader.png)              |
| emoji_hollow_star                       | `U+E106` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/other/hollow_star.png)                   |
| emoji_solid_star                        | `U+E107` | ![](https://wiki.bedrock.dev/assets/images/concepts/emojis/other/solid_star.png)                    |

### 逻辑运算

#### dict (字典)

- 参数:
  - `input`: 输入的键名
  - `...`: 其他键名

> **注意**: 字典会通过 input 的值来查找对应的键名, 如果找不到则不翻译

#### compare (比较)

- 参数:
  - `left`: 左侧值
  - `right`: 右侧值
  - `operator`: 比较运算符
    - 当`left`和`right`为数字时, 可以使用`==`, `!=`, `>`, `<`, `>=`, `<=`
    - 当`left`和`right`为字符串时, 可以使用`==`, `!=`, `include`, `startswith`, `endswith`, `regex`, `indexOf`
- 返回值示例: `true`, `false`

#### operation (运算)

- 参数:
  - `left`: 左侧值(需为数字)
  - `right`: 右侧值(需为数字)
  - `operator`: 运算符 (c++中运算符，非数学中的)
    - `+`: 加法
    - `-`: 减法
    - `*`: 乘法
    - `/`: 除法
    - `%`: 取余
    - `^`, `&`, `|`: 位运算
    - `>>`, `<<`: 移位运算

#### format (格式化)

- 参数:
  - `format`: 格式化字符串
  - `0..n`: 其他值
- 输入值示例: `${papi:format, format={}, 0=awa}`
- 返回值示例: `awa`

#### round (去除小数点)

- 参数:
  - `input`: 需要四舍五入的值
  - `decimals`: 保留的小数位数

> **注意**: 此为去除小数点，非四舍五入

#### slice (切片)

- 参数:
  - `input`: 需要切片的字符串
  - `start`: 切片开始位置(可为字符串也可为数字)
  - `end`: 切片结束位置(可为字符串也可为数字)

#### replace (单次替换)

- 参数:
  - `input`: 需要替换的字符串
  - `olaValue`: 需要被替换的字符串
  - `newValue`: 替换后的字符串

#### replaceAll (全部替换)

- 参数:
  - `input`: 需要替换的字符串
  - `olaValue`: 需要被替换的字符串
  - `newValue`: 替换后的字符串

#### join (拼接)

- 参数:
  - `separator`: 分隔符
  - `0..n`: 其他值

#### snake_case (转蛇形命名法)

- 参数:
  - `input`: 需要转换的字符串

#### camel_case (转驼峰命名法)

- 参数:
  - `input`: 需要转换的字符串

#### lower_case (转小写)

- 参数:
  - `input`: 需要转换的字符串

#### upper_case (转大写)

- 参数:
  - `input`: 需要转换的字符串

#### intToHexStr (整数转 16 进制字符串)

- 参数:
  - `input`: 需要转换的整数
  - `upperCase`: 是否为大写(默认为 true)
  - `no0x`: 是否不显示 0x(默认为 true)
  - `noLeadingZero`: 是否不显示前导零(默认为 true)

#### strToHexStr (字符串转 16 进制字符串)

- 参数:
  - `input`: 需要转换的字符串
  - `upperCase`: 是否为大写(默认为 false)
  - `addSpace`: 是否添加空格(默认为 false)

#### removeEscapeCode (去除转义字符)

- 参数:
  - `input`: 需要去除转义字符的字符串

#### doHash (哈希)

- 参数:
  - `input`: 需要哈希的字符串

#### doHash2 (哈希)

- 参数:
  - `input`: 需要哈希的字符串

#### doHash3 (哈希)

- 参数:
  - `input`: 需要哈希的字符串

#### random (随机数)

- 参数:
  - `min`: 最小值(默认为 0)
  - `max`: 最大值(默认为 100)

> **注意**: 当传入的其中一个值为浮点数时，返回值也为浮点数

#### scope (区间)

- 参数:
  - `input`: 需要判断的值
  - `default`: 默认返回值
  - `..`: 其他区间

> **注意**: 区间格式为`min..max`，例如`0..10`表示 0 到 10 之间的值，`10..`表示大于等于 10 的值，`..10`表示小于等于 10 的值

#### percentage (百分比)

- 参数:
  - `input`: 需要转换的值
  - `total`: 总值

#### translate_language (目标 Papi 翻译语言)

- 返回值示例: `zh_CN`

> **注意**: 此为 Papi 目标翻译语言，非 Minecraft 语言
