# Animation | 0003 | BPAnimBoneCube

## 0003_BPAnimBoneCube.blend

- The **Dope Sheet** and the **Action Editor** were opened in two new panels.
- In the **Actor Editor** toolbar (View, Select, Marker, etc), scroll the mouse wheel to view more buttons
- The **New Action** button was clicked to create a new animation, which was automatically titled "ArmatureAction.001"
- The new action was renamed to "ArmatureAction.Reciprocating"
- The auto duplicated keyframes were deleted
- The action "ArmatureAction.Reciprocating" had to be reselected after deleting the keyframes.
- The Bone object was selected and **Pose Mode** was activated
- A new keyframe at frame 1 was created with the Bone's default transform.
- A new keyframe at frame 16 was created with the Bone's transform scaled to 0.1 on the Z.
- A new keyframe at frame 32 was created with the Bone's default transform.
- Both animations will appear in `Scene Collection > Rig > Armature > Animation > NLA Tracks`
- The **Send to Unreal** operation was used, which created an Animation Sequence asset for each animation, ArmatureAction and ArmatureAction.Reciprocating

## Unreal

### BPAnimBoneCube_AB (Animation Blueprint)

- Parent Class = AnimInstance
- Target Skeleton = BPAnimBoneCube_Skeleton

- From the **Asset Browser** animations may be added to the **AnimGraph**; alternatively, they may be found by searching for "Play ..."

- A new **State Machine** was added to the **AnimGraph** titled "Idle_Recriprocating"
  - In the **My Blueprint** panel, a new variable **IsRecriprocating (boolean)** was added, which has a default value of false.
  - A **State** was added titled "Idle", which returns "Play ArmatureAction"
  - A **State** was added titled "Reciprocating", which returns "Play ArmatureAction_Reciprocating"
  - The **Transition Rule** from the **Idle** State to the **Reciprocating** State returns **IsReciprocating**
  - The **Transition Rule** from the **Reciprocating** State to the **Idle** State returns **!IsRecriprocating**
- The value of **IsReciprocating** is updated from **BPAnimBoneCube_BP**.

### BPAnimBoneCube_SM (Skeletal Mesh)

NA

### BPAnimBoneCube_Skeleton (Skeleton)

NA

### BPAnimBoneCube_PhysicsAsset (Physics Asset)

The **Primitive Type** was set to "Box" and the Bodies were regenerated.

### ArmatureAction (Animation Sequence)

NA

### ArmatureAction_Reciprocating (Animation Sequence)

NA

### BPAnimBoneCube_BP (Actor)

- **Skeletal Mesh Component**
  - **Skeletal Mesh** = "BPAnimBoneCube_SM"
  - **Animation Mode** = Use Animation Blueprint
  - **Anim Class** = BPAnimBoneCube_AB
  - **Collision Presets** = BlockAll
- **AnimBPInstance** is a variable of the type **BPAnimBoneCube_AB (Object Reference)**
- During **Begin Play** the anim instance is fetched from the SkeletalMesh component and saved to the variable **AnimBPInstance**
- A **Box Collision** component was added
  - **On Component Begin Overlap** enabled IsRecriprocating from the **AnimBPInstance** variable.
  - **On Component End Overlap** disabled IsRecriprocating from the **AnimBPInstance** variable.


