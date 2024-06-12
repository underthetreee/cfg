local wezterm = require 'wezterm'
local config = {
    use_fancy_tab_bar = false,
    show_new_tab_button_in_tab_bar = false,
    hide_tab_bar_if_only_one_tab = true,
    tab_bar_at_bottom = true,
    font_size = 9.5,
    freetype_load_target = "Light",
}

config.default_prog = { '/bin/bash', '-i' }

config.colors = {
  foreground = '#c8c8c8',
  background = '#0e0e0e',

  cursor_bg = '#c8c8c8',
  cursor_fg = '#0e0e0e',
  cursor_border = '#c8c8c8',

  selection_fg = '#0e0e0e',
  selection_bg = '#c8c8c8',

  ansi = {
      '#0e0e0e',
      '#bf616a',
      '#a3be8c',
      '#ebcb8b',
      '#81a1c1',
      '#b48ead',
      '#8fbcbb',
      '#c8c8c8',
  },

  brights = {
      '#4c566a',
      '#bf616a',
      '#a3be8c',
      '#ebcb8b',
      '#81a1c1',
      '#b48ead',
      '#8fbcbb',
      '#c8c8c8',
  },

  tab_bar = {
    background = '#0e0e0e',
    active_tab = {
      bg_color = '#0e0e0e',
      fg_color = '#c8c8c8',
    },

    inactive_tab = {
      bg_color = '#0e0e0e',
      fg_color = '#585858',
    },
  }
}

config.window_padding = {
  left = 0,
  right = 0,
  top = 0,
  bottom = 0,

}

config.disable_default_key_bindings = true
config.leader = { key = '`', mods = '', timeout_milliseconds = 1000 }
config.keys = {
  {
    key = 'c',
    mods = 'LEADER',
    action = wezterm.action.SpawnTab 'CurrentPaneDomain'
  },

  {
    key = 'd',
    mods = 'LEADER',
    action = wezterm.action.CloseCurrentTab{confirm=false}
  },

  {
    key = 'C',
    mods = 'CTRL',
    action = wezterm.action.CopyTo 'Clipboard',
  },

  {
    key = 'V',
    mods = 'CTRL',
    action = wezterm.action.PasteFrom 'Clipboard',
  },

  {
    key = '`',
    mods = 'LEADER',
    action = wezterm.action.ActivateLastTab,
  },
}

for i = 1, 9 do
  table.insert(config.keys, {
    key = tostring(i),
    mods = 'LEADER',
    action = wezterm.action.ActivateTab(i - 1),
  })
end

return config
