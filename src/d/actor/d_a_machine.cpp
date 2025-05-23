//
// Generated by dtk
// Translation Unit: d_a_machine.cpp
//

#include "d/actor/d_a_machine.h"
#include "m_Do/m_Do_ext.h"
#include "d/d_procname.h"
#include "d/d_priority.h"

/* 00000078-000000A8       .text _delete__11daMachine_cFv */
bool daMachine_c::_delete() {
    /* Nonmatching */
}

/* 000000A8-000000C8       .text CheckCreateHeap__FP10fopAc_ac_c */
static BOOL CheckCreateHeap(fopAc_ac_c*) {
    /* Nonmatching */
}

/* 000000C8-0000022C       .text CreateHeap__11daMachine_cFv */
void daMachine_c::CreateHeap() {
    /* Nonmatching */
}

/* 0000022C-000002A0       .text nodeCallBack__FP7J3DNodei */
static BOOL nodeCallBack(J3DNode*, int) {
    /* Nonmatching */
}

/* 000002A0-00000520       .text CreateInit__11daMachine_cFv */
void daMachine_c::CreateInit() {
    /* Nonmatching */
}

/* 00000520-00000604       .text path_move__11daMachine_cFv */
void daMachine_c::path_move() {
    /* Nonmatching */
}

/* 00000604-00000700       .text set_next_pnt__11daMachine_cFv */
void daMachine_c::set_next_pnt() {
    /* Nonmatching */
}

/* 00000700-00000734       .text search_wind_mill__11daMachine_cFv */
void daMachine_c::search_wind_mill() {
    /* Nonmatching */
}

/* 00000734-000007F8       .text set_speed__11daMachine_cFv */
void daMachine_c::set_speed() {
    /* Nonmatching */
}

/* 000007F8-00000898       .text _create__11daMachine_cFv */
cPhs_State daMachine_c::_create() {
    /* Nonmatching */
}

/* 00000F74-0000100C       .text set_mtx__11daMachine_cFv */
void daMachine_c::set_mtx() {
    /* Nonmatching */
}

/* 0000100C-000010F8       .text _execute__11daMachine_cFv */
bool daMachine_c::_execute() {
    /* Nonmatching */
}

/* 000010F8-0000124C       .text attack__11daMachine_cFv */
void daMachine_c::attack() {
    /* Nonmatching */
}

/* 0000124C-00001330       .text set_cube__11daMachine_cFv */
void daMachine_c::set_cube() {
    /* Nonmatching */
}

/* 00001330-0000144C       .text set_body__11daMachine_cFv */
void daMachine_c::set_body() {
    /* Nonmatching */
}

/* 0000144C-000014D4       .text set_at__11daMachine_cFv */
void daMachine_c::set_at() {
    /* Nonmatching */
}

/* 000014D4-0000154C       .text _draw__11daMachine_cFv */
bool daMachine_c::_draw() {
    /* Nonmatching */
}

/* 0000154C-0000156C       .text daMachine_Create__FPv */
static cPhs_State daMachine_Create(void*) {
    /* Nonmatching */
}

/* 0000156C-00001590       .text daMachine_Delete__FPv */
static BOOL daMachine_Delete(void*) {
    /* Nonmatching */
}

/* 00001590-000015B4       .text daMachine_Draw__FPv */
static BOOL daMachine_Draw(void*) {
    /* Nonmatching */
}

/* 000015B4-000015D8       .text daMachine_Execute__FPv */
static BOOL daMachine_Execute(void*) {
    /* Nonmatching */
}

/* 000015D8-000015E0       .text daMachine_IsDelete__FPv */
static BOOL daMachine_IsDelete(void*) {
    /* Nonmatching */
}

static actor_method_class daMachineMethodTable = {
    (process_method_func)daMachine_Create,
    (process_method_func)daMachine_Delete,
    (process_method_func)daMachine_Execute,
    (process_method_func)daMachine_IsDelete,
    (process_method_func)daMachine_Draw,
};

actor_process_profile_definition g_profile_MACHINE = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0007,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_MACHINE,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daMachine_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ PRIO_MACHINE,
    /* Actor SubMtd */ &daMachineMethodTable,
    /* Status       */ fopAcStts_CULL_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
