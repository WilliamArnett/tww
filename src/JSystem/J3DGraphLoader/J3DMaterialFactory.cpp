//
// Generated by dtk
// Translation Unit: J3DMaterialFactory.cpp
//

#include "JSystem/J3DGraphLoader/J3DMaterialFactory.h"
#include "JSystem/J3DGraphLoader/J3DModelLoader.h"
#include "JSystem/J3DGraphBase/J3DMatBlock.h"
#include "JSystem/JSupport/JSupport.h"

/* 802F68F0-802F6B38       .text __ct__18J3DMaterialFactoryFRC16J3DMaterialBlock */
J3DMaterialFactory::J3DMaterialFactory(const J3DMaterialBlock& block) {
    mMaterialNum = block.mMaterialNum;
    mpMaterialInitData = JSUConvertOffsetToPtr<J3DMaterialInitData>(&block, block.mpMaterialInitData);
    mpMaterialID = JSUConvertOffsetToPtr<u16>(&block, block.mpMaterialID);

    if (block.mpIndInitData != NULL && ((u32)block.mpIndInitData - (u32)block.mpNameTable) > 4)
        mpIndInitData = JSUConvertOffsetToPtr<J3DIndInitData>(&block, block.mpIndInitData);
    else
        mpIndInitData = NULL;

    mpCullMode = JSUConvertOffsetToPtr<GXCullMode>(&block, block.mpCullMode);
    mpMatColor = JSUConvertOffsetToPtr<GXColor>(&block, block.mpMatColor);
    mpColorChanNum = JSUConvertOffsetToPtr<u8>(&block, block.mpColorChanNum);
    mpColorChanInfo = JSUConvertOffsetToPtr<J3DColorChanInfo>(&block, block.mpColorChanInfo);
    mpAmbColor = JSUConvertOffsetToPtr<GXColor>(&block, block.mpAmbColor);
    mpLightInfo = JSUConvertOffsetToPtr<J3DLightInfo>(&block, block.mpLightInfo);
    mpTexGenNum = JSUConvertOffsetToPtr<u8>(&block, block.mpTexGenNum);
    mpTexCoordInfo = JSUConvertOffsetToPtr<J3DTexCoordInfo>(&block, block.mpTexCoordInfo);
    mpTexCoord2Info = JSUConvertOffsetToPtr<J3DTexCoord2Info>(&block, block.mpTexCoord2Info);
    mpTexMtxInfo = JSUConvertOffsetToPtr<J3DTexMtxInfo>(&block, block.mpTexMtxInfo);
    field_0x44 = JSUConvertOffsetToPtr<J3DTexMtxInfo>(&block, block.field_0x44);
    mpTexNo = JSUConvertOffsetToPtr<u16>(&block, block.mpTexNo);
    mpTevOrderInfo = JSUConvertOffsetToPtr<J3DTevOrderInfo>(&block, block.mpTevOrderInfo);
    mpTevColor = JSUConvertOffsetToPtr<GXColorS10>(&block, block.mpTevColor);
    mpTevKColor = JSUConvertOffsetToPtr<GXColor>(&block, block.mpTevKColor);
    mpTevStageNum = JSUConvertOffsetToPtr<u8>(&block, block.mpTevStageNum);
    mpTevStageInfo = JSUConvertOffsetToPtr<J3DTevStageInfo>(&block, block.mpTevStageInfo);
    mpTevSwapModeInfo = JSUConvertOffsetToPtr<J3DTevSwapModeInfo>(&block, block.mpTevSwapModeInfo);
    mpTevSwapModeTableInfo = JSUConvertOffsetToPtr<J3DTevSwapModeTableInfo>(&block, block.mpTevSwapModeTableInfo);
    mpFogInfo = JSUConvertOffsetToPtr<J3DFogInfo>(&block, block.mpFogInfo);
    mpAlphaCompInfo = JSUConvertOffsetToPtr<J3DAlphaCompInfo>(&block, block.mpAlphaCompInfo);
    mpBlendInfo = JSUConvertOffsetToPtr<J3DBlendInfo>(&block, block.mpBlendInfo);
    mpZModeInfo = JSUConvertOffsetToPtr<J3DZModeInfo>(&block, block.mpZModeInfo);
    mpZCompLoc = JSUConvertOffsetToPtr<u8>(&block, block.mpZCompLoc);
    mpDither = JSUConvertOffsetToPtr<u8>(&block, block.mpDither);
    mpNBTScaleInfo = JSUConvertOffsetToPtr<J3DNBTScaleInfo>(&block, block.mpNBTScaleInfo);
    mpDisplayListInit = NULL;
    mpPatchingInfo = NULL;
    mpCurrentMtxInfo = NULL;
    field_0x84 = NULL;
}

/* 802F6B38-802F6BC0       .text __ct__18J3DMaterialFactoryFRC18J3DMaterialDLBlock */
J3DMaterialFactory::J3DMaterialFactory(const J3DMaterialDLBlock& block) {
    mMaterialNum = block.mMaterialNum;
    mpMaterialInitData = NULL;
    mpDisplayListInit = JSUConvertOffsetToPtr<J3DDisplayListInit>(&block, block.mpDisplayListInit);
    mpPatchingInfo = JSUConvertOffsetToPtr<J3DPatchingInfo>(&block, block.mpPatchingInfo);
    mpCurrentMtxInfo = JSUConvertOffsetToPtr<J3DCurrentMtxInfo>(&block, block.mpCurrentMtxInfo);
    field_0x84 = JSUConvertOffsetToPtr<u8>(&block, block.field_0x18);
}

/* 802F6BC0-802F6C08       .text countUniqueMaterials__18J3DMaterialFactoryFv */
u16 J3DMaterialFactory::countUniqueMaterials() {
    u16 num = 0;
    s32 maxID = -1;
    for (u16 i = 0; i < mMaterialNum; i++) {
        if (maxID < mpMaterialID[i]) {
            num++;
            maxID = mpMaterialID[i];
        }
    }
    return num;
}

/* 802F6C08-802F6C40       .text countTexGens__18J3DMaterialFactoryCFi */
u32 J3DMaterialFactory::countTexGens(int idx) const {
    u8 no = mpMaterialInitData[mpMaterialID[idx]].mTexGenNumIdx;
    if (no != 0xFF)
        return mpTexGenNum[no];
    return 0;
}

/* 802F6C40-802F6CC8       .text countStages__18J3DMaterialFactoryCFi */
u32 J3DMaterialFactory::countStages(int idx) const {
    J3DMaterialInitData* initData = &mpMaterialInitData[mpMaterialID[idx]];

    u32 texGenNum = 0;
    u32 tevStageNum = 0;

    u8 no = initData->mTevStageNumIdx;
    if (no != 0xFF)
        tevStageNum = mpTevStageNum[no];

    for (s32 i = 0; i < 8; i++)
        if (initData->mTexNoIdx[i] != 0xFFFF)
            texGenNum++;

    if (tevStageNum != texGenNum && texGenNum != 0) {
        return tevStageNum > texGenNum ? tevStageNum : texGenNum;
    } else {
        return tevStageNum;
    }
}

/* 802F6CC8-802F6D44       .text create__18J3DMaterialFactoryCFP11J3DMaterialQ218J3DMaterialFactory12MaterialTypeiUl */
J3DMaterial* J3DMaterialFactory::create(J3DMaterial* mat, MaterialType type, int idx, u32 flag) const {
    switch (type) {
    case MATERIAL_TYPE_NORMAL:
        mat = createNormalMaterial(mat, idx, flag);
        break;
    case MATERIAL_TYPE_LOCKED:
        mat = createLockedMaterial(mat, idx, flag);
        break;
    case MATERIAL_TYPE_PATCHED:
        mat = createPatchedMaterial(mat, idx, flag);
        break;
    }
    return mat;
}

/* 802F6D44-802F768C       .text createNormalMaterial__18J3DMaterialFactoryCFP11J3DMaterialiUl */
J3DMaterial* J3DMaterialFactory::createNormalMaterial(J3DMaterial* mat, int idx, u32 i_flags) const {
    if (mpDisplayListInit != NULL)
        return createLockedMaterial(mat, idx, i_flags);

    const u32 stages = countStages(idx);
    u32 tev_stage_num = getMdlDataFlag_TevStageNum(i_flags);
    u32 tev_stage_num_max = stages > tev_stage_num ? stages : tev_stage_num;
    u32 tex_num = tev_stage_num_max > 8 ? 8 : tev_stage_num_max;
    u32 tex_gens = countTexGens(idx);
    u32 tex_gen_flag = tex_gens > 4 ? getMdlDataFlag_TexGenFlag(0) : getMdlDataFlag_TexGenFlag(i_flags);
    u32 color_block_flag = getMdlDataFlag_ColorFlag(i_flags);
    u32 pe_flag = getMdlDataFlag_PEFlag(i_flags);
    BOOL ind_flag = (i_flags & 0x1000000) ? TRUE : FALSE;

    if (mat == NULL)
        mat = new J3DMaterial();

    mat->mColorBlock = J3DMaterial::createColorBlock(color_block_flag);
    mat->mTexGenBlock = J3DMaterial::createTexGenBlock(tex_gen_flag);
    mat->mTevBlock = J3DMaterial::createTevBlock((u16)tev_stage_num_max);
    mat->mIndBlock = J3DMaterial::createIndBlock(ind_flag);
    mat->mPEBlock = J3DMaterial::createPEBlock(pe_flag, getMaterialMode(idx));
    mat->mIndex = idx;
    mat->mMaterialMode = getMaterialMode(idx);
    mat->mColorBlock->setColorChanNum(newColorChanNum(idx));
    mat->mColorBlock->setCullMode(newCullMode(idx));
    mat->mTexGenBlock->setTexGenNum(newTexGenNum(idx));
    mat->mTexGenBlock->setNBTScale(newNBTScale(idx));
    mat->mPEBlock->setFog(newFog(idx));
    mat->mPEBlock->setAlphaComp(newAlphaComp(idx));
    mat->mPEBlock->setBlend(newBlend(idx));
    mat->mPEBlock->setZMode(newZMode(idx));
    mat->mPEBlock->setZCompLoc(newZCompLoc(idx));
    mat->mPEBlock->setDither(newDither(idx));
    mat->mTevBlock->setTevStageNum(newTevStageNum(idx));

    for (u8 i = 0; i < tex_num; i++)
        mat->mTevBlock->setTexNo(i, newTexNo(idx, i));
    for (u8 i = 0; i < tev_stage_num_max; i++)
        mat->mTevBlock->setTevOrder(i, newTevOrder(idx, i));
    for (u8 i = 0; i < tev_stage_num_max; i++) {
        J3DMaterialInitData* initData = &mpMaterialInitData[mpMaterialID[idx]];
        mat->mTevBlock->setTevStage(i, newTevStage(idx, i));
        if (initData->mTevSwapModeIdx[i] != 0xFFFF) {
            mat->mTevBlock->getTevStage(i)->setTexSel(mpTevSwapModeInfo[initData->mTevSwapModeIdx[i]].mTexSel);
            mat->mTevBlock->getTevStage(i)->setRasSel(mpTevSwapModeInfo[initData->mTevSwapModeIdx[i]].mRasSel);
        }
    }
    for (u8 i = 0; i < 4; i++)
        mat->mTevBlock->setTevKColor(i, newTevKColor(idx, i));
    for (u8 i = 0; i < 4; i++)
        mat->mTevBlock->setTevColor(i, newTevColor(idx, i));
    for (u8 i = 0; i < 4; i++)
        mat->mTevBlock->setTevSwapModeTable(i, newTevSwapModeTable(idx, i));
    for (u8 i = 0; i < 2; i++)
        mat->mColorBlock->setAmbColor(i, newAmbColor(idx, i));
    for (u8 i = 0; i < 2; i++)
        mat->mColorBlock->setMatColor(i, newMatColor(idx, i));
    for (u8 i = 0; i < 4; i++) {
        J3DColorChan colorChan = newColorChan(idx, i);
        mat->mColorBlock->setColorChan(i, colorChan);
    }
    for (u8 i = 0; i < tex_gens; i++) {
        J3DTexCoord texCoord = newTexCoord(idx, i);
        mat->mTexGenBlock->setTexCoord(i, &texCoord);
    }
    for (u8 i = 0; i < 8; i++) {
        mat->mTexGenBlock->setTexMtx(i, newTexMtx(idx, i));
    }
    J3DMaterialInitData* initData = &mpMaterialInitData[mpMaterialID[idx]];
    for (u8 i = 0; i < tev_stage_num_max; i++) {
        if (initData->mTevKColorSel[i] != 0xff) {
            mat->mTevBlock->setTevKColorSel(i, initData->mTevKColorSel[i]);
        } else {
            mat->mTevBlock->setTevKColorSel(i, 0xc);
        }
    }
    for (u8 i = 0; i < tev_stage_num_max; i++) {
        if (initData->mTevKAlphaSel[i] != 0xff) {
            mat->mTevBlock->setTevKAlphaSel(i, initData->mTevKAlphaSel[i]);
        } else {
            mat->mTevBlock->setTevKAlphaSel(i, 0x1c);
        }
    }
    if (mpIndInitData != NULL) {
        u8 indTexStageNum = newIndTexStageNum(idx);
        mat->mIndBlock->setIndTexStageNum(newIndTexStageNum(idx));
        for (u8 i = 0; i < indTexStageNum; i++)
            mat->mIndBlock->setIndTexMtx(i, newIndTexMtx(idx, i));
        for (u8 i = 0; i < indTexStageNum; i++)
            mat->mIndBlock->setIndTexOrder(i, newIndTexOrder(idx, i));
        for (u8 i = 0; i < indTexStageNum; i++)
            mat->mIndBlock->setIndTexCoordScale(i, newIndTexCoordScale(idx, i));
        for (u8 i = 0; i < tev_stage_num_max; i++)
            mat->mTevBlock->setIndTevStage(i, newIndTevStage(idx, i));
    }
    return mat;
}

/* 802F768C-802F7F98       .text createPatchedMaterial__18J3DMaterialFactoryCFP11J3DMaterialiUl */
J3DMaterial* J3DMaterialFactory::createPatchedMaterial(J3DMaterial* mat, int idx, u32 flag) const {
    if (mat == NULL)
        mat = new J3DPatchedMaterial();

    bool indFlag = (flag & 0x03000000) ? true : false; // fakematch?
    mat->mColorBlock = J3DMaterial::createColorBlock(0x40000000);

    mat->mTexGenBlock = new J3DTexGenBlockPatched();
    mat->mTevBlock = new J3DTevBlockPatched();
    mat->mIndBlock = J3DMaterial::createIndBlock(indFlag);
    mat->mPEBlock = J3DMaterial::createPEBlock(0x10000000, getMaterialMode(idx));
    mat->mIndex = idx;
    mat->mMaterialMode = getMaterialMode(idx);
    mat->mTevBlock->setTevStageNum(newTevStageNum(idx));
    mat->mColorBlock->setColorChanNum(newColorChanNum(idx));
    mat->mColorBlock->setCullMode(newCullMode(idx));
    mat->mPEBlock->setFog(newFog(idx));
    mat->mPEBlock->setAlphaComp(newAlphaComp(idx));
    mat->mPEBlock->setBlend(newBlend(idx));
    mat->mPEBlock->setZMode(newZMode(idx));
    mat->mPEBlock->setZCompLoc(newZCompLoc(idx));
    mat->mPEBlock->setDither(newDither(idx));

    u8 tevStageNum = mat->mTevBlock->getTevStageNum();
    for (u8 i = 0; i < 8; i++)
        mat->mTevBlock->setTexNo(i, newTexNo(idx, i));
    for (u8 i = 0; i < tevStageNum; i++)
        mat->mTevBlock->setTevOrder(i, newTevOrder(idx, i));
    for (u8 i = 0; i < 4; i++)
        mat->mTevBlock->setTevKColor(i, newTevKColor(idx, i));
    for (u8 i = 0; i < 4; i++)
        mat->mTevBlock->setTevColor(i, newTevColor(idx, i));
    for (u8 i = 0; i < tevStageNum; i++) {
        J3DMaterialInitData* initData = &mpMaterialInitData[mpMaterialID[idx]];
        mat->mTevBlock->setTevStage(i, newTevStage(idx, i));
        if (initData->mTevSwapModeIdx[i] != 0xFFFF) {
            mat->mTevBlock->getTevStage(i)->setTexSel(mpTevSwapModeInfo[initData->mTevSwapModeIdx[i]].mTexSel);
            mat->mTevBlock->getTevStage(i)->setRasSel(mpTevSwapModeInfo[initData->mTevSwapModeIdx[i]].mRasSel);
        }
    }
    J3DMaterialInitData* initData = &mpMaterialInitData[mpMaterialID[idx]];
    for (u8 i = 0; i < tevStageNum; i++) {
        if (initData->mTevKColorSel[i] != 0xff) {
            mat->mTevBlock->setTevKColorSel(i, initData->mTevKColorSel[i]);
        } else {
            mat->mTevBlock->setTevKColorSel(i, 0xc);
        }
    }
    for (u8 i = 0; i < 2; i++)
        mat->mColorBlock->setMatColor(i, newMatColor(idx, i));
    for (u8 i = 0; i < 4; i++) {
        J3DColorChan colorChan = newColorChan(idx, i);
        mat->mColorBlock->setColorChan(i, colorChan);
    }

    u32 texGenNum = countTexGens(idx);
    mat->mTexGenBlock->setTexGenNum(newTexGenNum(idx));
    for (u8 i = 0; i < 8; i++)
        mat->mTexGenBlock->setTexMtx(i, newTexMtx(idx, i));
    for (u8 i = 0; i < texGenNum; i++) {
        J3DTexCoord texCoord = newTexCoord(idx, i);
        mat->mTexGenBlock->setTexCoord(i, &texCoord);
    }
    if (indFlag && mpIndInitData != NULL) {
        u8 indTexStageNum = newIndTexStageNum(idx);
        mat->mIndBlock->setIndTexStageNum(newIndTexStageNum(idx));
        for (u8 i = 0; i < indTexStageNum; i++)
            mat->mIndBlock->setIndTexMtx(i, newIndTexMtx(idx, i));
        for (u8 i = 0; i < indTexStageNum; i++)
            mat->mIndBlock->setIndTexOrder(i, newIndTexOrder(idx, i));
        for (u8 i = 0; i < indTexStageNum; i++)
            mat->mIndBlock->setIndTexCoordScale(i, newIndTexCoordScale(idx, i));
        for (u8 i = 0; i < tevStageNum; i++)
            mat->mTevBlock->setIndTevStage(i, newIndTevStage(idx, i));
    }
    return mat;
}

/* 802F7F98-802F80F8       .text modifyPatchedCurrentMtx__18J3DMaterialFactoryCFP11J3DMateriali */
void J3DMaterialFactory::modifyPatchedCurrentMtx(J3DMaterial* mat, int idx) const {
    J3DTexCoord coord[8];
    u32 texGenNum = countTexGens(idx);
    for (u8 i = 0; i < texGenNum; i++)
        coord[i] = newTexCoord(idx, i);
    mat->mCurrentMtx.setCurrentTexMtx(
        coord[0].getTexGenMtx(),
        coord[1].getTexGenMtx(),
        coord[2].getTexGenMtx(),
        coord[3].getTexGenMtx(),
        coord[4].getTexGenMtx(),
        coord[5].getTexGenMtx(),
        coord[6].getTexGenMtx(),
        coord[7].getTexGenMtx()
    );
}

/* 802F80F8-802F83A0       .text createLockedMaterial__18J3DMaterialFactoryCFP11J3DMaterialiUl */
J3DMaterial* J3DMaterialFactory::createLockedMaterial(J3DMaterial* mat, int idx, u32 flag) const {
    if (mat == NULL) {
        mat = new J3DLockedMaterial();
        mat->mColorBlock = new J3DColorBlockNull();
        mat->mTexGenBlock = new J3DTexGenBlockNull();
        mat->mTevBlock = new J3DTevBlockNull();
        mat->mIndBlock = new J3DIndBlockNull();
        mat->mPEBlock = new J3DPEBlockNull();
        mat->mIndex = idx;
        mat->mMaterialMode = field_0x84[idx];
    }

    mat->mCurrentMtx = mpCurrentMtxInfo[idx];
    mat->mColorBlock->setMatColorOffset(mpPatchingInfo[idx].mMatColorOffset);
    mat->mColorBlock->setColorChanOffset(mpPatchingInfo[idx].mColorChanOffset);
    mat->mTexGenBlock->setTexMtxOffset(mpPatchingInfo[idx].mTexMtxOffset);
    mat->mTevBlock->setTexNoOffset(mpPatchingInfo[idx].mTexNoOffset);
    mat->mTevBlock->setTevRegOffset(mpPatchingInfo[idx].mTevRegOffset);
    mat->mPEBlock->setFogOffset(mpPatchingInfo[idx].mFogOffset);
    if (mat->mSharedDLObj == NULL) {
        mat->mSharedDLObj = new J3DDisplayListObj();
        mat->mSharedDLObj->setSingleDisplayList((void*)(mpDisplayListInit[idx].mOffset + (u32)&mpDisplayListInit[idx]), mpDisplayListInit[idx].mSize);
    }
    return mat;
}

/* 802F83A0-802F8420       .text calcSize__18J3DMaterialFactoryCFP11J3DMaterialQ218J3DMaterialFactory12MaterialTypeiUl */
u32 J3DMaterialFactory::calcSize(J3DMaterial* mat, MaterialType type, int idx, u32 flag) const {
    u32 ret = 0;
    switch (type) {
    case MATERIAL_TYPE_NORMAL:
        ret = calcSizeNormalMaterial(mat, idx, flag);
        break;
    case MATERIAL_TYPE_LOCKED:
        ret = calcSizeLockedMaterial(mat, idx, flag);
        break;
    case MATERIAL_TYPE_PATCHED:
        ret = calcSizePatchedMaterial(mat, idx, flag);
        break;
    }
    return ret;
}

/* 802F8420-802F8554       .text calcSizeNormalMaterial__18J3DMaterialFactoryCFP11J3DMaterialiUl */
u32 J3DMaterialFactory::calcSizeNormalMaterial(J3DMaterial* i_material, int i_idx, u32 i_flags) const {
    u32 size = 0;
    if (mpDisplayListInit != NULL) {
        return calcSizeLockedMaterial(i_material, i_idx, i_flags);
    }

    const u32 stages = countStages(i_idx);
    u32 tev_stage_num = getMdlDataFlag_TevStageNum(i_flags);
    u32 tev_stage_num_max = stages > tev_stage_num ? stages : tev_stage_num;
    u32 tex_num = tev_stage_num_max > 8 ? 8 : tev_stage_num_max;
    u32 tex_gens = countTexGens(i_idx);
    u32 tex_gen_flag = tex_gens > 4 ? getMdlDataFlag_TexGenFlag(0) : getMdlDataFlag_TexGenFlag(i_flags);
    u32 color_block_flag = getMdlDataFlag_ColorFlag(i_flags);
    u32 pe_flag = getMdlDataFlag_PEFlag(i_flags);
    BOOL ind_flag = (i_flags & 0x1000000) ? TRUE : FALSE;
    if (i_material == NULL) {
        size += sizeof(J3DMaterial);
    }
    size += J3DMaterial::calcSizeColorBlock(color_block_flag);
    size += J3DMaterial::calcSizeTexGenBlock(tex_gen_flag);
    size += J3DMaterial::calcSizeTevBlock((u16)tev_stage_num_max);
    size += J3DMaterial::calcSizeIndBlock(ind_flag);
    size += J3DMaterial::calcSizePEBlock(pe_flag, getMaterialMode(i_idx));
    J3DMaterialInitData* init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    for (int i = 0; i < 8; i++) {
        if (init_data->mTexMtxIdx[i] != 0xffff) {
            size += sizeof(J3DTexMtx);
        }
    }
    size += 0x2C; // TODO what is 0x2C bytes?
    return size;
}

/* 802F8554-802F8624       .text calcSizePatchedMaterial__18J3DMaterialFactoryCFP11J3DMaterialiUl */
u32 J3DMaterialFactory::calcSizePatchedMaterial(J3DMaterial* i_material, int i_idx, u32 i_flags) const {
    u32 size = 0;
    if (i_material == NULL) {
        size = sizeof(J3DPatchedMaterial);
    }
    bool ind_flag = !!(i_flags & 0x03000000) ? true : false; // fakematch? order gets messed up if you remove the ternary
    size += J3DMaterial::calcSizeColorBlock(0x40000000);
    size += sizeof(J3DTexGenBlockPatched);
    size += sizeof(J3DTevBlockPatched);
    size += J3DMaterial::calcSizeIndBlock(ind_flag);
    size += J3DMaterial::calcSizePEBlock(0x10000000, getMaterialMode(i_idx));
    J3DMaterialInitData* init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    for (int i = 0; i < 8; i++) {
        if (init_data->mTexMtxIdx[i] != 0xffff) {
            size += sizeof(J3DTexMtx);
        }
    }
    size += 0x2C; // TODO what is 0x2C bytes?
    return size;
}

/* 802F8624-802F863C       .text calcSizeLockedMaterial__18J3DMaterialFactoryCFP11J3DMaterialiUl */
u32 J3DMaterialFactory::calcSizeLockedMaterial(J3DMaterial* i_material, int i_idx, u32 i_flags) const {
    u32 size = 0;
    if (i_material == NULL) {
        size = sizeof(J3DLockedMaterial) + sizeof(J3DColorBlockNull) + sizeof(J3DTexGenBlockNull)
            + sizeof(J3DTevBlockNull) + sizeof(J3DIndBlockNull) + sizeof(J3DPEBlockNull);
    }
    return size + sizeof(J3DDisplayListObj);
}

/* 802F863C-802F86CC       .text newMatColor__18J3DMaterialFactoryCFii */
J3DGXColor J3DMaterialFactory::newMatColor(int idx, int stage) const {
    GXColor _ret = { 0xFF, 0xFF, 0xFF, 0xFF };
    J3DGXColor ret(_ret);
    u16 no = mpMaterialInitData[mpMaterialID[idx]].mMatColorIdx[stage];
    if (no != 0xFFFF)
        return mpMatColor[no];
    else
        return ret;
}

/* 802F86CC-802F8704       .text newColorChanNum__18J3DMaterialFactoryCFi */
u8 J3DMaterialFactory::newColorChanNum(int idx) const {
    u8 no = mpMaterialInitData[mpMaterialID[idx]].mColorChanNumIdx;
    if (no != 0xFF)
        return mpColorChanNum[no];
    else
        return 0;
}

/* 802F8704-802F88A8       .text newColorChan__18J3DMaterialFactoryCFii */
J3DColorChan J3DMaterialFactory::newColorChan(int idx, int stage) const {
    u16 no = mpMaterialInitData[mpMaterialID[idx]].mColorChanIdx[stage];
    if (no != 0xFFFF)
        return J3DColorChan(mpColorChanInfo[no]);
    else
        return J3DColorChan();
}

/* 802F88A8-802F8938       .text newAmbColor__18J3DMaterialFactoryCFii */
J3DGXColor J3DMaterialFactory::newAmbColor(int idx, int stage) const {
    GXColor _ret = { 0x32, 0x32, 0x32, 0x32 };
    J3DGXColor ret(_ret);
    u16 no = mpMaterialInitData[mpMaterialID[idx]].mAmbColorIdx[stage];
    if (no != 0xFFFF)
        return mpAmbColor[no];
    else
        return ret;
}

/* 802F8938-802F8970       .text newTexGenNum__18J3DMaterialFactoryCFi */
u32 J3DMaterialFactory::newTexGenNum(int idx) const {
    u8 no = mpMaterialInitData[mpMaterialID[idx]].mTexGenNumIdx;
    if (no != 0xFF)
        return mpTexGenNum[no];
    else
        return 0;
}

/* 802F8970-802F89E4       .text newTexCoord__18J3DMaterialFactoryCFii */
J3DTexCoord J3DMaterialFactory::newTexCoord(int idx, int stage) const {
    u16 no = mpMaterialInitData[mpMaterialID[idx]].mTexCoordIdx[stage];
    if (no != 0xFFFF)
        return J3DTexCoord(mpTexCoordInfo[no]);
    else
        return J3DTexCoord();
}

/* 802F89E4-802F8AF4       .text newTexMtx__18J3DMaterialFactoryCFii */
J3DTexMtx* J3DMaterialFactory::newTexMtx(int idx, int stage) const {
    J3DTexMtx* ret = NULL;
    J3DMaterialInitData* initData = &mpMaterialInitData[mpMaterialID[idx]];
    if (initData->mTexMtxIdx[stage] != 0xFFFF)
        ret = new J3DTexMtx(mpTexMtxInfo[initData->mTexMtxIdx[stage]]);
    return ret;
}

/* 802F8AF4-802F8B34       .text newCullMode__18J3DMaterialFactoryCFi */
u8 J3DMaterialFactory::newCullMode(int idx) const {
    u8 no = mpMaterialInitData[mpMaterialID[idx]].mCullModeIdx;
    if (no != 0xFF)
        return mpCullMode[no];
    else
        return 0xFF;
}

/* 802F8B34-802F8B7C       .text newTexNo__18J3DMaterialFactoryCFii */
u16 J3DMaterialFactory::newTexNo(int idx, int stage) const {
    u16 no = mpMaterialInitData[mpMaterialID[idx]].mTexNoIdx[stage];
    if (no != 0xFFFF)
        return mpTexNo[no];
    else
        return 0xFFFF;
}

/* 802F8B7C-802F8BF0       .text newTevOrder__18J3DMaterialFactoryCFii */
J3DTevOrder J3DMaterialFactory::newTevOrder(int idx, int stage) const {
    u16 no = mpMaterialInitData[mpMaterialID[idx]].mTevOrderIdx[stage];
    if (no != 0xFFFF)
        return J3DTevOrder(mpTevOrderInfo[no]);
    else
        return J3DTevOrder();
}

/* 802F8BF0-802F8C88       .text newTevColor__18J3DMaterialFactoryCFii */
J3DGXColorS10 J3DMaterialFactory::newTevColor(int idx, int stage) const {
    GXColorS10 _ret = { 0x00, 0x00, 0x00, 0x00 };
    J3DGXColorS10 ret(_ret);
    u16 no = mpMaterialInitData[mpMaterialID[idx]].mTevColorIdx[stage];
    if (no != 0xFFFF)
        return mpTevColor[no];
    else
        return ret;
}

/* 802F8C88-802F8D18       .text newTevKColor__18J3DMaterialFactoryCFii */
J3DGXColor J3DMaterialFactory::newTevKColor(int idx, int stage) const {
    GXColor _ret = { 0xFF, 0xFF, 0xFF, 0xFF };
    J3DGXColor ret(_ret);
    u16 no = mpMaterialInitData[mpMaterialID[idx]].mTevKColorIdx[stage];
    if (no != 0xFFFF)
        return mpTevKColor[no];
    else
        return ret;
}

/* 802F8D18-802F8D50       .text newTevStageNum__18J3DMaterialFactoryCFi */
u8 J3DMaterialFactory::newTevStageNum(int idx) const {
    u8 no = mpMaterialInitData[mpMaterialID[idx]].mTevStageNumIdx;
    if (no != 0xFF)
        return mpTevStageNum[no];
    else
        return 0xFF;
}

/* 802F8D50-802F8DB0       .text newTevStage__18J3DMaterialFactoryCFii */
J3DTevStage J3DMaterialFactory::newTevStage(int idx, int stage) const {
    u16 no = mpMaterialInitData[mpMaterialID[idx]].mTevStageIdx[stage];
    if (no != 0xFFFF)
        return J3DTevStage(mpTevStageInfo[no]);
    else
        return J3DTevStage();
}

/* 802F8DB0-802F8E4C       .text newTevSwapModeTable__18J3DMaterialFactoryCFii */
J3DTevSwapModeTable J3DMaterialFactory::newTevSwapModeTable(int idx, int stage) const {
    u16 no = mpMaterialInitData[mpMaterialID[idx]].mTevSwapModeTableIdx[stage];
    if (no != 0xFFFF)
        return J3DTevSwapModeTable(mpTevSwapModeTableInfo[no]);
    else
        return J3DTevSwapModeTable(j3dDefaultTevSwapModeTable);
}

/* 802F8E4C-802F8E74       .text newIndTexStageNum__18J3DMaterialFactoryCFi */
u8 J3DMaterialFactory::newIndTexStageNum(int idx) const {
    if (mpIndInitData[idx].mEnabled == true)
        return mpIndInitData[idx].mIndTexStageNum;
    else
        return 0;
}

/* 802F8E74-802F8ED4       .text newIndTexOrder__18J3DMaterialFactoryCFii */
J3DIndTexOrder J3DMaterialFactory::newIndTexOrder(int idx, int stage) const {
    J3DIndTexOrder ret;
    if (mpIndInitData[idx].mEnabled == true)
        return J3DIndTexOrder(mpIndInitData[idx].mIndTexOrderInfo[stage]);
    else
        return ret;
}

/* 802F8ED4-802F8FD0       .text newIndTexMtx__18J3DMaterialFactoryCFii */
J3DIndTexMtx J3DMaterialFactory::newIndTexMtx(int idx, int stage) const {
    J3DIndTexMtx ret;
    if (mpIndInitData[idx].mEnabled == true)
        return J3DIndTexMtx(mpIndInitData[idx].mIndTexMtxInfo[stage]);
    else
        return ret;
}

/* 802F8FD0-802F9164       .text newIndTevStage__18J3DMaterialFactoryCFii */
J3DIndTevStage J3DMaterialFactory::newIndTevStage(int idx, int stage) const {
    J3DIndTevStage ret;
    if (mpIndInitData[idx].mEnabled == true)
        return J3DIndTevStage(mpIndInitData[idx].mIndTevStageInfo[stage]);
    else
        return ret;
}

/* 802F9164-802F91C4       .text newIndTexCoordScale__18J3DMaterialFactoryCFii */
J3DIndTexCoordScale J3DMaterialFactory::newIndTexCoordScale(int idx, int stage) const {
    J3DIndTexCoordScale ret;
    if (mpIndInitData[idx].mEnabled == true)
        return J3DIndTexCoordScale(mpIndInitData[idx].mIndTexCoordScaleInfo[stage]);
    else
        return ret;
}

/* 802F91C4-802F9348       .text newFog__18J3DMaterialFactoryCFi */
J3DFog* J3DMaterialFactory::newFog(int idx) const {
    J3DMaterialInitData* initData = &mpMaterialInitData[mpMaterialID[idx]];
    if (initData->mFogIdx != 0xFFFF)
        return new J3DFog(mpFogInfo[initData->mFogIdx]);
    else
        return new J3DFog();
}

/* 802F9348-802F93C8       .text newAlphaComp__18J3DMaterialFactoryCFi */
J3DAlphaComp J3DMaterialFactory::newAlphaComp(int idx) const {
    u16 no = mpMaterialInitData[mpMaterialID[idx]].mAlphaCompIdx;
    if (no != 0xFFFF)
        return J3DAlphaComp(mpAlphaCompInfo[no]);
    else
        return J3DAlphaComp(0xFFFF);
}

/* 802F93C8-802F9444       .text newBlend__18J3DMaterialFactoryCFi */
J3DBlend J3DMaterialFactory::newBlend(int idx) const {
    u16 no = mpMaterialInitData[mpMaterialID[idx]].mBlendIdx;
    if (no != 0xFFFF)
        return J3DBlend(mpBlendInfo[no]);
    else
        return J3DBlend();
}

/* 802F9444-802F94A4       .text newZMode__18J3DMaterialFactoryCFi */
J3DZMode J3DMaterialFactory::newZMode(int idx) const {
    u8 no = mpMaterialInitData[mpMaterialID[idx]].mZModeIdx;
    if (no != 0xFF)
        return J3DZMode(mpZModeInfo[no]);
    else
        return J3DZMode();
}

/* 802F94A4-802F94DC       .text newZCompLoc__18J3DMaterialFactoryCFi */
u8 J3DMaterialFactory::newZCompLoc(int idx) const {
    u8 no = mpMaterialInitData[mpMaterialID[idx]].mZCompLocIdx;
    if (no != 0xFF)
        return mpZCompLoc[no];
    else
        return 0;
}

/* 802F94DC-802F9514       .text newDither__18J3DMaterialFactoryCFi */
u8 J3DMaterialFactory::newDither(int idx) const {
    u8 no = mpMaterialInitData[mpMaterialID[idx]].mDitherIdx;
    if (no != 0xFF)
        return mpDither[no];
    else
        return 1;
}

/* 802F9514-802F95B8       .text newNBTScale__18J3DMaterialFactoryCFi */
J3DNBTScale J3DMaterialFactory::newNBTScale(int idx) const {
    J3DNBTScale ret;
    u16 no = mpMaterialInitData[mpMaterialID[idx]].mNBTScaleIdx;
    if (no != 0xFFFF)
        return J3DNBTScale(mpNBTScaleInfo[no]);
    else
        return ret;
}
