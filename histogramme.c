void remplir_fichiers(AVL a, FILE* Fmax, FILE* Fcapt, FILE* Freel){
    if(a == NULL){
         return;
    }

    if(a->usine == NULL){
        return;
    }

    remplir_fichiers(a->fd, Fmax, Fcapt, Freel);

    fprintf(Fmax,  "%s;%.2f\n", a->id, a->usine->volume_max);
    fprintf(Fcapt,  "%s;%.2f\n", a->id, a->usine->volume_capte);
    fprintf(Freel, "%s;%.2f\n", a->id, a->usine->volume_reel);

    remplir_ficher(AVL a, Fmax, Fcapt, Freel);
})
