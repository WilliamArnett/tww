//
// Generated by dtk
// Translation Unit: d_a_himo2.cpp
//

#include "d/actor/d_a_himo2.h"
#include "d/d_procname.h"
#include "d/d_priority.h"

/* 800EB60C-800EBABC       .text spin_draw__FP11himo2_class */
void spin_draw(himo2_class*) {
    /* Nonmatching */
}

/* 800EBABC-800EBCD0       .text himo2_control__FP11himo2_classP7himo2_s */
void himo2_control(himo2_class*, himo2_s*) {
    /* Nonmatching */
}

/* 800EBCD0-800EBFEC       .text himo2_control2__FP11himo2_classP7himo2_s */
void himo2_control2(himo2_class*, himo2_s*) {
    /* Nonmatching */
}

/* 800EBFEC-800EC1E4       .text himo2_draw__FP11himo2_classP7himo2_s */
void himo2_draw(himo2_class*, himo2_s*) {
    /* Nonmatching */
}

/* 800EC1E4-800EC300       .text himo_hang_draw__FP11himo2_class */
void himo_hang_draw(himo2_class*) {
    /* Nonmatching */
}

/* 800EC300-800EC338       .text himo2_disp__FP11himo2_class */
void himo2_disp(himo2_class*) {
    /* Nonmatching */
}

/* 800EC338-800ECBE8       .text daHimo2_Draw__FP11himo2_class */
static BOOL daHimo2_Draw(himo2_class*) {
    /* Nonmatching */
}

/* 800ECBE8-800ECC54       .text s_a_d_sub__FPvPv */
void s_a_d_sub(void*, void*) {
    /* Nonmatching */
}

/* 800ECC54-800ED19C       .text search_target__FP11himo2_class4cXyz */
void search_target(himo2_class*, cXyz) {
    /* Nonmatching */
}

/* 800ED19C-800ED2E0       .text setTargetPos__11himo2_classFP4cXyzPfPf */
BOOL himo2_class::setTargetPos(cXyz*, float*, float*) {
    /* Nonmatching */
}

/* 800ED2E0-800ED32C       .text dr_a_sub__FPvPv */
void dr_a_sub(void*, void*) {
    /* Nonmatching */
}

/* 800ED32C-800ED378       .text b_a_sub__FPvPv */
void b_a_sub(void*, void*) {
    /* Nonmatching */
}

/* 800ED378-800ED688       .text himo2_bg_check__FP11himo2_class */
void himo2_bg_check(himo2_class*) {
    /* Nonmatching */
}

/* 800ED688-800ED6F4       .text pl_pos_add__FP11himo2_class */
void pl_pos_add(himo2_class*) {
    /* Nonmatching */
}

/* 800ED6F4-800F0038       .text new_himo2_move__FP11himo2_class */
void new_himo2_move(himo2_class*) {
    /* Nonmatching */
}

/* 800F01BC-800F062C       .text daHimo2_Execute__FP11himo2_class */
static BOOL daHimo2_Execute(himo2_class*) {
    /* Nonmatching */
}

/* 800F062C-800F0634       .text daHimo2_IsDelete__FP11himo2_class */
static BOOL daHimo2_IsDelete(himo2_class*) {
    /* Nonmatching */
}

/* 800F0634-800F0670       .text daHimo2_Delete__FP11himo2_class */
static BOOL daHimo2_Delete(himo2_class*) {
    /* Nonmatching */
}

/* 800F0670-800F07F4       .text CallbackCreateHeap__FP10fopAc_ac_c */
static BOOL CallbackCreateHeap(fopAc_ac_c*) {
    /* Nonmatching */
}

/* 800F07F4-800F0B08       .text daHimo2_Create__FP10fopAc_ac_c */
static cPhs_State daHimo2_Create(fopAc_ac_c*) {
    /* Nonmatching */
}

/* 800F0B98-800F0BE0       .text __dt__10himo2HIO_cFv */
himo2HIO_c::~himo2HIO_c() {
    /* Nonmatching */
}

static actor_method_class l_daHimo2_Method = {
    (process_method_func)daHimo2_Create,
    (process_method_func)daHimo2_Delete,
    (process_method_func)daHimo2_Execute,
    (process_method_func)daHimo2_IsDelete,
    (process_method_func)daHimo2_Draw,
};

actor_process_profile_definition g_profile_HIMO2 = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0008,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_HIMO2,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(himo2_class),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ PRIO_HIMO2,
    /* Actor SubMtd */ &l_daHimo2_Method,
    /* Status       */ fopAcStts_UNK4000_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_0_e,
};
