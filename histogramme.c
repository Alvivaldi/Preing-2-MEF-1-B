void remplir_fichiers(AVL* a, FILE* Fmax, FILE* Fcapt, FILE* Freel){
    if(a == NULL){
         return;
    }

    remplir_fichiers(a->fd, Fmax, Fcapt, Freel);

    fprintf(Fmax,  "%s;%.2f\n", a->id, a->usine->volume_max);
    fprintf(Fcapt,  "%s;%.2f\n", a->id, a->usine->volume_capt);
    fprintf(Freel, "%s;%.2f\n", a->id, a->usine->volume_reel);

    remplir_ficher(a->fg, Fmax, Fcapt, Freel);
}

void generer_fichiers_histogramme(AVL* a){
    FILE *Fmax  = fopen("vol_max.dat", "w");
    FILE *Fcapt  = fopen("vol_captation.dat", "w");
    FILE *Freel = fopen("vol_traitement.dat", "w");
    if(Fmax == NULL || Fcapt == NULL || Freel == NULL){
        printf("erreur ouverture fichiers histogramme");
        exit(1);
    }
    fprintf(Fmax,  "id;volume_max\n");
    fprintf(Fcapt,  "id;volume_captation\n");
    fprintf(Freel, "id;volume_traitement\n");
    remplir_fichiers(a, Fmax, Fcapt, Freel);
    fclose(Fmax);
    fclose(Fcapt);
    fclose(Freel);
}