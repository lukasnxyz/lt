### LaTeX Template System
lt makes creating new latex projects and files easier by using your own templates and placing them in your own project directory.

#### Options
```bash
-h  help
-t  type of template
-n  name of project
```

#### Setup
Give the path of your `.tex` templates folder in config.h, but make sure that there is a foreward slash (/) at the end of the path.

#### Quick Start
```bash
sudo make install
lt -t mla -n name_of_project
```

#### Todo
- Add more templates
- Fix memory issues with strcat and memcpy
- Fix opening file warning (integer to pointer conversion assigning to 'FILE \*')
- Add ability to use with markdown as well (-l for language ie. latex, markdown, etc.)
