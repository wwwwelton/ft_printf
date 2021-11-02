# ft_printf
My reimplementation of the [printf](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm), the goal is to compile a library containing our [libft](https://github.com/wwwwelton/libft) functions and our own version of the printf function.

### What is ft_printf?
[ft_printf](https://github.com/wwwwelton/ft_printf) is an individual project at [42](42sp.org.br) that requires us to create our own version of the [printf()](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm) function. In C programming language, printf() function is used to print the ("character, string, float, integer, octal and hexadecimal values") onto the output screen, returning the number of characters written.

### Badge
<img src="./images/ft_printfm.png" width="150" height="150"/>

#### Objectives
- Unix logic

#### Skills
- Rigor
- Algorithms & AI

#### My grade
<img src="./images/score.png" width="150" height="150"/>


## Getting started
**Follow the steps below**
```bash
# Clone the project and access the folder
git clone https://github.com/wwwwelton/ft_printf && cd ft_printf/

# Run make so you can build the library
make bonus

# Create a main file
touch main.c
```

```c
/*
** Example of a main function
*/

#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello World");
	return (0);
}
```

```bash
# Compile your main with the library, example:
clang main.c libftprintf.a

# Execute your program
./a.out

# Clean output objects with
make fclean

# Well done!
```

## Commonly Used Format Specifiers
The general prototype of [format specifiers](https://www.programiz.com/cpp-programming/library-function/cstdio/printf) implemented is:
<code>%[flags][width][.precision]specifier</code>

The table below lists commonly used implemented format specifiers:

<table>
    <thead>
        <tr>
            <th colspan=3><h4>Function</h4></th>
        </tr>
        <tr>
            <th>Name</th>
            <th>Prototype</th>
        </tr>
    </thead>
    <tbody>
	</thead>
        <tr>
            <td align="center">ft_printf</td>
            <td>ft_printf(const char* format, ...)</td>
        </tr>
    </tbody>
        <tr>
            <th colspan=3><h4>Flags</h4></th>
        </tr>
        <tr>
            <th>Flag</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
	</thead>
        <tr>
            <td align="center">-</td>
            <td>Left justify the result within the field. By default it is right justified.</td>
        </tr>
        <tr>
            <td align="center">+</td>
            <td>Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a sign.</td>
        </tr>
        <tr>
            <td align="center">(space)</td>
            <td>If there is no sign, a space is attached to the beginning of the result.</td>
        </tr>
        <tr>
            <td align="center">#</td>
            <td>Used with x or X specifiers the value is preceded with 0x or 0X respectively for values different than zero.</td>
        </tr>
        <tr>
            <td align="center">0</td>
            <td>Leading zeros are used to pad the numbers instead of space.</td>
        </tr>
    </tbody>
	<thead>
        <tr>
            <th colspan=3><h4>Width</h4></th>
        </tr>
        <tr>
            <th>Value</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
	</thead>
        <tr>
            <td align="center">(number)</td>
            <td>Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.</td>
        </tr>
        <tr>
            <td align="center">*</td>
            <td>The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.</td>
        </tr>
    </tbody>
	<thead>
        <tr>
            <th colspan=3><h4>Precision</h4></th>
        </tr>
        <tr>
            <th>Value</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
	</thead>
        <tr>
            <td align="center">.(number)</td>
            <td>For integer specifiers (d, i, u, x, X) − precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For s − this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. For c type − it has no effect. When no precision is specified, the default is 1. If the period is specified without an explicit value for precision, 0 is assumed.</td>
        </tr>
        <tr>
            <td align="center">.(*)</td>
            <td>The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=3><h4>Specifiers</h4></th>
        </tr>
        <tr>
            <th>Format Specifier</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
	</thead>
        <tr>
            <td align="center">%</td>
            <td>% followed by another % character writes % to the screen.</td>
        </tr>
        <tr>
            <td align="center">c</td>
            <td>writes a single character.</td>
        </tr>
        <tr>
            <td align="center">s</td>
            <td>writes a character string.</td>
        </tr>
        <tr>
            <td align="center">p</td>
            <td>writes an implementation-defined character sequence defining a pointer address.</td>
        </tr>
        <tr>
            <td align="center">d or i</td>
            <td>writes a signed integer to decimal representation.</td>
        </tr>
        <tr>
            <td align="center">u</td>
            <td>writes an unsigned integer to decimal representation.</td>
        </tr>
        <tr>
            <td align="center">x or X</td>
            <td>writes an unsigned integer to hexadecimal representation.</td>
        </tr>
    </tbody>
</table>

## Updating

The project is regularly updated with bug fixes and code optimization.

## 📝 License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](license) file for details.

---

Made by Welton Leite 👋 [See my linkedin](https://www.linkedin.com/in/welton-leite-b3492985/)
