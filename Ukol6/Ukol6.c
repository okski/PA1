typedef struct word_t { char * a; int size; int count;} Word;

void add (Word * arr, char znak) {
    if (arr->count == arr->size) {
        if (arr->size == 0) {
            arr->size = 4;
        } else {
            arr->size += 1; 
        }
        arr->a = (char*) realloc(arr->a, arr->size * sizeof(char));
    }
    arr->a[arr->count] = znak;
    arr->count++;
}

int readword (Word* text, const char * src, int start, int maxlength, int *promenlivadelka) {
    int i = start - 1;
    int countnewline = 0;
    while (1) {
        i++;
        if (text->count > maxlength) {
            return -1;
        }
        if (src[i] == ' ' || src[i] == '\t') {
            if (text->a == NULL) {
                continue;
            }
            *promenlivadelka = i;
            return text->count;
        } else if (src[i] == '\n') {
            countnewline++;
            if (text->a == NULL) {
                continue;
            }
            *promenlivadelka = i;
            return text->count;
        } else if (src[i] == '\0') {
            add (text, '\n');
            add (text, '\0');
            return -2;
        } else if (countnewline > 1) {
            add(text, '\n');
            add(text, '\n');
            *promenlivadelka = i;
            return -3;
        }
        add (text, src[i]);
    }
    return  -1;
}

typedef struct format_t {char * text; int size; int count; int lastnewline;}Creatingtext;

char * creating (Creatingtext * text, Word * word, int delkaslova, int width) {
    if (text->count == text->size) {
        if (text->size == 0) {
            text->size = word->count;
        } else if (text->lastnewline != text->count) {
            text->size += 1 + word->count; 
        } else {
            text->size += word->count; 
        }
        text->text = (char*) realloc(text->text, text->size * sizeof(char));
    }
        if ((text->count > 0) && (text->lastnewline != text->count)) {
            if (text->count + delkaslova + 1 <= width + text->lastnewline) {
                text->text[text->count] = ' ';
                text->count++;
            } else {
                text->text[text->count] = '\n';
                text->count++;
                text->lastnewline = text->count;
            }
        }
    for (int i = 0; i < word->count; i++) {
        text->text[text->count] = word->a[i];
        text->count++;
    }
    
    if (word->count != delkaslova){
        text->lastnewline = text->count;
    }
    return 0;
}

char * wordWrap ( int width, const char * src) {
    Creatingtext text = {NULL, 0, 0, 0};
    int start = 0;
    int delkaslova = 1;
    int promenlivadelka = 0;
    while ( delkaslova > 0) {
        Word puvodnitext = {NULL, 0, 0};
        delkaslova = readword(&puvodnitext, src, start, width, &promenlivadelka);
        start = promenlivadelka;
        if (delkaslova == -1) {
            printf("\n");
            return NULL;
        }
        if (delkaslova == -2) {
            text.lastnewline = text.count;
        }
        if (delkaslova == -3) {
            text.lastnewline = text.count;
            delkaslova = 1;
        }
        if (puvodnitext.a != NULL) {
            creating(&text, &puvodnitext, delkaslova, width);
        }
        free(puvodnitext.a);
    }
    return text.text;
}