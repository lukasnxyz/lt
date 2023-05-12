### Latex Template System (lt)

#### Description
lt makes creating new latex projects and files easier by using your own templates and placing them in your own project directory.

#### Options
<code>-h</code>  help<br>
<code>-t</code>  type of template<br>
<code>-n</code>  name of project<br>

#### Setup
Give the path of your <code>.tex</code> templates folder in config.h, but make sure that there is a foreward slash (/) at the end of the path.

#### Usage
Example: <code>lt -t mla -n project</code><br>
Eake sure that the type you enter is the same as the name of the template that you wish to use (without the <code>.tex</code> extension).

#### Todo
* Fix memory issues with strcat and memcpy
* Fix opening file warning (integer to pointer conversion assigning to 'FILE \*')
* Add ability to use with markdown as well
