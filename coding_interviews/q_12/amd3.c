/*
Int:
*/

/*

Examples of features - in C
- Redfish

server

workstation

app with 100 modules
diff between C and python

app. in C vs.

app.

feature OOB -

polymorphism

which data structure in OOB

array
linked list
trees
graphs

//

stack , linked list, or

queue, list linked, array,

///

cat

ls

cd

grep

cp file lnux -> linux // check sum file hash /// md5 hash //

// data is getting corrupted //


ftp
sftp

ssh


//

txt


*/


/*

Interviewer:

Francisco.

* My questions:
    * MacOS? What do you use? // Linux vs. Windows. Depending
    * what percentage of your time is spent on programming, debugging, and reading technical documentation? What if any, activities do you do outside of these broad categories. // %80
    * what programming language do you use the most? Bash Ruby Python.
    * what was the last program you wrote? Manual -> Automate.
    * Most challenging tech. problem worked on. -> Allot of tools. Redfish commands. Python comm. to HW.
    * How often - interface with BIOS team. x86 -> AMD or Intel.
        * Chance to write C code.
        * Chance to look at BIOS code.

QA team->Test team->BIOS team.
*/



#first question, replace hello by hallo in the string below
data_in_text = "dapko;dsakdsakl;dsakldsaklhellojsdondlsjdsalnkjdlsa"
replace_text = ["hello", 'hallo']

int replace(char *old, char *new) {
    // TODO arg checks
    while (old != '\0') {
        *old = *new; // overwrite
    }

    return 0; // success
}

/*
 Normally - use a function in string.h
 char *replace_text -> old, new

 //
*/
int replace_str(char *data_in_text, char *old_s, char *new_s) {
    /// TODO args check

    if (data_in_text == NULL ....)
        return 1; // error
// strcmp(s0, s0)

    // replace occurrences of replace_text in data_in_text
    // scan data_in_text, if you find replace_text replace it!

    /*
        IMPORTANT! consider relative length of replace text
        if shorter "hello", "hell" -> the string's is shorter after the
        replacement!!!

        if longer, then the ouput string will need more space!!!!

        Account for strange inputs,  like searching for empty string!!!
    */
    while (data_in_text != '\0') {

        if (strcmp(data_in_text, replace_text) == 0) { // old string and new string are equal in length.
            // match
            replace(data_in_text, new_s);
        }

        data_in_text++;
    }

    return 0; // success
}


