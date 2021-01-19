# Animation | 0002 | Anim Bone Cube

## 0002_AnimBoneCube.blend

The BoneCube.blend file was duplicated using the Save As operation before proceeding to animate the cube.

- The **Armature** object was selected and **Pose Mode** was activated.
- The Timeline's End frame was decreased from 250 to 32
- A new keyframe was created at frame 1 using the Armature's unmodified transform
- A new keyframe was created at frame 16 after rotating the Armature on the Z axis 90 degrees.
- A new keyframe was created at frame 32 after resetting the Armature's rotation.
- Finally the **Send To Unreal** operation was used, which created four assets
  - Cube (Skeletal Mesh)
  - Cube_Skeleton (Skeleton)
  - Cube_PhysicsAsset (Physics Asset)
  - An animations folder with ArmatureAction (Animation Sequence)

## BP_AnimBoneCube (Actor)

A new actor was created and a **Skeletal Mesh Component** was added and its **Skeletal Mesh** property
was assigned to **AnimBoneCube**.

Its **Animation Mode** was changed to **Use Animation Asset** and its **Anim to Play** property
was set to **AnimBoneCube_ArmatureAction**. It immediately began playing in the Viewport.

When an instance of the actor is added to the level, it will not play in the level unless Simulate or
a new PIE instance is launched.

Similarly its **Collision Presets** property defaulted to **NoCollision** and it was changed to **Block All**.

## AnimBoneCube_PhysicsAsset

Similar to BoneCube, its **Primitive Type** was set to **Box** and the Bodies were regenerated.

