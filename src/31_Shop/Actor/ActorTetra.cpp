#include "Actor/Character/ActorTetra.hpp"
#include "DTCM/UnkStruct_027e0fec.hpp"
#include "Save/AdventureFlags.hpp"

extern u32 **data_027e0fe0[];
extern UnkStruct_027e0fec *data_027e0fec;
extern unk32 sUnk1;
extern unk32 sUnk2;

extern void CleanDataCacheLines(void *ptr, unsigned int size);
extern bool func_02017d30(bool, unk32, ActorTetra_4cc *, unk32);

ARM ActorTetra *ActorTetra::Create() {
    return new(*data_027e0fe0[0], 4) ActorTetra();
}

ARM bool ActorTetra::vfunc_f4() {
    static const unk32 sUnk1[] = {0x800, 0x4cd, 0x10cd};

    if (gAdventureFlags->Get(AdventureFlag_PlayedBellumTakesOverGhostShipCS)) {
        return false;
    }
    mUnk_1d8.func_ov014_02145a74(0x37, 0x37);
    mUnk_1d8.func_ov014_02145ae8(0x37, "TTR", "sekika");
    func_ov014_021451f0(sUnk1);
    mUnk_448 = 4;
    if (mUnk_020.mUnk_00[0] == 0 && mUnk_020.mUnk_00[2] == 1) {
        mUnk_1d8.mUnk_18          = &sUnk2;
        mUnk_1d8.mUnk_020.mUnk_8e = true;
        mUnk_1d8.func_ov014_02146120(0);
        mUnk_469         = true;
        mUnk_468         = true;
        mUnk_4b0.mUnk_04 = 0;
        mUnk_4b0.mUnk_00 = 0x1000;
    }
    mUnk_4b0.func_ov031_02181610(data_027e0fec->mUnk_c10, 0x800, 0x800, 0x800, 0x318C);
    return true;
}

ARM void ActorTetra::vfunc_c4() {
    if (mUnk_020.mUnk_00[0] == 0 && mUnk_020.mUnk_00[2] == 1) {
        mUnk_1d8.mUnk_10->mUnk_0c.mUnk_04 = 0;
    }
    ActorGenericCharacter::vfunc_c4();
}

ARM void ActorTetra::vfunc_20(bool param1) {
    bool state = param1 ? mUnk_0a4.mUnk_01 : mUnk_0a4.mUnk_00;
    if (!state) {
        return;
    }
    ActorCharacter::vfunc_20(param1);
    mUnk_4b0.func_ov031_02181798();
}

ARM void ActorTetra_4b0::func_ov031_02181610(func_ov031_02181610_param1 *tex_ptr, unk32 param2, unk32 param3, unk32 param4,
                                             u16 param5) {
    this->mUnk_08 = (unk32 *) ((unk32) tex_ptr + tex_ptr->mUnk_38);
    this->mUnk_18 = ((u32) (tex_ptr->mUnk_2c << 16) >> 13);

    size_t size = tex_ptr->mUnk_30 * 8;

    if (size > this->size) {
        size = this->size;
    }
    if (size < this->size) {
        this->size = size;
    }
    unk32 tempcool = (param5 & 31);
    unk32 temp4    = (param5 & 0x3e0) >> 5;
    unk32 temp5    = (param5 & 0x7c00) >> 10;

    unk32 temp9 = size >> 1;

    u16 *pSrc  = (u16 *) this->mUnk_08;
    u16 *pDest = (u16 *) this->mUnk_0c;
    q20 temp11 = ROUND_Q20(param2 * CoDivide64By32(INT_TO_Q20(31), INT_TO_Q20(tempcool + 31)));
    q20 temp6  = ROUND_Q20(param3 * CoDivide64By32(INT_TO_Q20(31), INT_TO_Q20(temp4 + 31)));
    q20 temp14 = ROUND_Q20(param4 * CoDivide64By32(INT_TO_Q20(31), INT_TO_Q20(temp5 + 31)));

    for (int var2 = 0; var2 < temp9; var2++) {
        unk32 temp10_2 = (*pSrc & 31) + ((*pSrc >> 5) & 31) + ((*pSrc >> 10) & 31);

        unk32 var3 = (unk32) ((temp10_2 * temp11) + ((u32) (param5 << 27) >> 15)) >> 12;
        if (var3 > 31) {
            var3 = 31;
        }
        unk32 varip = ((temp10_2 * temp6) + INT_TO_Q20(temp4)) >> 12;
        if (varip > 31) {
            varip = 31;
        }
        unk32 var0 = (unk32) ((temp10_2 * temp14) + INT_TO_Q20(temp5)) >> 12;
        if (var0 > 31) {
            var0 = 31;
        }
        *pDest = var3 | (varip << 5) | (var0 << 10);
        pDest++;
        pSrc++;
    }
    CleanDataCacheLines(this->mUnk_0c, size);
}

ARM void ActorTetra_4b0::func_ov031_02181798() {
    unk32 uVar1;
    int iVar2;
    int iVar3;
    u32 uVar4;
    int iVar5;
    unk32 *puVar6;
    int iVar7;
    u32 uVar8;
    unk32 *puVar9;
    unk32 *puVar10;
    unk32 iVar11;

    if (this->mUnk_00 == this->mUnk_04) {
        return;
    }
    this->mUnk_04 = this->mUnk_00;
    uVar1         = this->size;
    iVar7         = 0;
    puVar6        = (unk32 *) this->mUnk_10;
    puVar9        = this->mUnk_08;
    puVar10       = (unk32 *) this->mUnk_0c;
    if (uVar1 >> 1 != 0) {
        for (int i = 0; i < uVar1 >> 1; i++) {
            uVar8   = (unk32) *puVar10;
            uVar4   = (u32) *puVar9;
            iVar2   = this->mUnk_00;
            iVar3   = 0x1000 - iVar2;
            iVar11  = (uVar4 & 0x1f) * iVar3 + (uVar8 & 0x1f) * iVar2;
            iVar5   = ((int) (uVar4 & 0x7c00) >> 10) * iVar3 + ((int) (uVar8 & 0x7c00) >> 10) * iVar2 >> 0xc;
            *puVar6 = (u16) ((((int) (uVar4 & 0x3e0) >> 5) * iVar3 + ((int) (uVar8 & 0x3e0) >> 5) * iVar2 >> 0xc) << 5) |
                      (u16) (iVar11 >> 0xc) | (u16) (iVar5 << 10);
            puVar6  = puVar6 + 1;
            puVar9  = puVar9 + 1;
            puVar10 = puVar10 + 1;
        }
    }
    CleanDataCacheLines(this->mUnk_10, this->size);
    func_02017d30(true, this->mUnk_18, this->mUnk_10, this->size);
}
